#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange( char *inputFilePath )
	: _inputFilePath( inputFilePath ) {

	  };

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) {
	(void)other;
};

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other ) {
	(void)other;

	return *this;
};

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::loadBtcDatabase( std::ifstream &file ) {

	std::string line, date;
	float rate;

	// Skipping header
	std::getline( file, line );

	while ( std::getline( file, line ) ) {

		date = getDate( line, ',' );
		rate = getValue( line, ',' );

		if ( !checkDateFormat( date ) || rate == VALUE_ERROR ) {
			return ERROR;
		} else
			_bctData[date] = rate;
	};

	return SUCCESS;
};

float getValue( const std::string &line, char sep ) {

	std::string valueStr;
	size_t sepPos;

	sepPos = line.find( sep );
	if ( sepPos == std::string::npos ) {
		std::cerr << "Error: missing separator in line: " << line << std::endl;
		return VALUE_ERROR;
	}
	try {

		valueStr = trim( line.substr( sepPos + 1 ) );
		std::stringstream ss( valueStr );
		float value;
		ss >> value;
		if ( ss.fail() || !ss.eof() ) {
			throw std::exception();
		}
		return value;
	} catch ( const std::exception &e ) {
		std::cerr << "Error: invalid number in line: " << line << std::endl;
		return VALUE_ERROR;
	}
};


static bool isBi(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static int getDaywithMonth(int year, int month) {
	
	int monthsDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (isBi(year) && month == 1) {
		return 29;
	};

	return monthsDays[month];
}


bool checkDateFormat( const std::string &date ) {

	std::string format;
	struct tm tm = {};


	format = "%Y-%m-%d";

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
	
	if ( !strptime( date.c_str(), format.c_str(), &tm ) )
		return ERROR;
	

	if (tm.tm_mday > getDaywithMonth(tm.tm_year + 1900, tm.tm_mon))
		return ERROR;

	return SUCCESS;
};

std::string getDate( std::string line, const char sep ) {

	size_t sepPos;
	std::string date = "";

	sepPos = line.find( sep );

	if ( sepPos == std::string::npos )
		return date;

	return line.substr( 0, sepPos );
};

bool openFile( std::ifstream &file, const std::string &path ) {

	file.open( path.c_str() );

	if ( !file.is_open() )
		return false;
	return true;
};

void displayOutput( std::string inputLine, std::string &date, float exchangeValue ) {

	std::string display;
	size_t sepPos = inputLine.find( '|' );

	display = date + " => ";
	display += trim( inputLine.substr( sepPos + 1 ) );
	display += " = ";
	std::cout << display << exchangeValue << std::endl;
};

static bool parseBadInput( const std::string &line ) {

	size_t sepPos;
	std::string date;

	sepPos = line.find( '|' );

	date = getDate( line, '|' );
	if ( ( sepPos == std::string::npos ) || ( sepPos != line.rfind( '|' ) ) || !checkDateFormat( date ) )
		return ERROR;

	return SUCCESS;
};

static bool parseValue( float valueF ) {

	if ( valueF < 0 ) {
		std::cerr << "Error: not a positive number." << std::endl;
		return ERROR;
	} else if ( valueF >= 1000 || valueF == 0 ) {
		std::cerr << "Error: Numbers must be between 0 and 1000." << std::endl;
		return ERROR;
	} else if ( valueF == VALUE_ERROR ) {
		return ERROR;
	};

	return SUCCESS;
}

void BitcoinExchange::processTransactions( std::ifstream &inputFile ) {

	size_t sepPos;
	std::string line, date;
	float rate, exchangeValue, value;

	// Skip header
	std::getline( inputFile, line );
	std::cout << "\n";
	while ( std::getline( inputFile, line ) ) {

		if ( parseBadInput( line ) == ERROR ) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		};

		sepPos = line.find( '|' );

		date = trim( line.substr( 0, sepPos ) );
		value = getValue( line, '|' );
		if ( parseValue( value ) == ERROR )
			continue;

		// Now its success to find a match line in data and show result
		rate = getClosestRate( date, _bctData );

		if ( rate == VALUE_ERROR ) {
			std::cerr << "Error: Date '" << trim( getDate( line, '|' ) ) << "' out of dataBase." << std::endl;
			continue;
		};

		exchangeValue = rate * value;
		displayOutput( line, date, exchangeValue );
	};
};

std::string trim( const std::string &s ) {

	size_t start, end;

	start = s.find_first_not_of( " \t\n\r\v" );
	if ( start == std::string::npos )
		return "";

	end = s.find_last_not_of( " \t\n\r\f\v" );

	return s.substr( start, end - start + 1 );
}

long ft_stol( const std::string &src ) {
	long result;
	bool isNegative;
	size_t i;

	result = 0;
	isNegative = false;
	i = 0;

	if ( src.empty() )
		return 0;

	if ( src[0] == '-' ) {
		isNegative = true;
		i++;
	}

	for ( ; i < src.size(); i++ ) {
		if ( src[i] < '0' || src[i] > '9' )
			break; // stop at first non-digit
		result = result * 10 + ( src[i] - '0' );
	}

	return isNegative ? -result : result;
}

void BitcoinExchange::run() {

	std::ifstream btcFile, inputFile;

	if ( !openFile( btcFile, DATA_PATH ) )
		throw BtcError::OpenFile( DATA_PATH );

	if ( !openFile( inputFile, _inputFilePath ) ) {
		btcFile.close();
		throw BtcError::OpenFile( _inputFilePath );
	};

	if ( !loadBtcDatabase( btcFile ) ) {
		btcFile.close();
		inputFile.close();
		throw BtcError::Base( "Error: Wrong btcDataBate." );
	};

	processTransactions( inputFile );

	btcFile.close();
	inputFile.close();
};

bool parseDateFormat( std::string &date ) {

	std::string format( "%Y-%m-%d" );
	struct tm tm = {};

	if ( !strptime( date.c_str(), format.c_str(), &tm ) )
		return false;

	return true;
};

static size_t getSumTotalTime( std::string time ) {

	size_t firstDash, lastDash, totalTime;
	std::string year, month, day;

	firstDash = time.find( '-' );
	lastDash = time.rfind( '-' );

	year = time.substr( 0, firstDash );
	month = time.substr( firstDash + 1, lastDash - firstDash - 1 );
	day = time.substr( lastDash + 1 );

	std::string concatenatedString = year + month + day;

	totalTime = ft_stol( concatenatedString );
	if ( totalTime == std::string::npos )
		return 1.0f;
	return totalTime;
};

float getClosestRate( const std::string &date, std::map< std::string, float > &btcContainer ) {

	size_t inputTotalDate = getSumTotalTime( date );
	std::string closestDate;
	float closestValue = 0.0f;

	for ( std::map< std::string, float >::iterator it = btcContainer.begin(); it != btcContainer.end(); ++it ) {
		size_t btcTotalDate = getSumTotalTime( it->first );

		if ( btcTotalDate <= inputTotalDate ) {
			closestDate = it->first;
			closestValue = it->second;
		} else {
			break;
		}
	}

	if ( closestDate.empty() ) {
		return -1.0f;
	}

	return closestValue;
};