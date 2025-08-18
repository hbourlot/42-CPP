#include "../inc/BitcoinExchange.hpp"
#include <fstream>

/// @brief Executes the Bitcoin exchange workflow.
/// Opens the BTC database file and the user-provided input file,
/// loads the exchange rates into memory, processes each transaction,
/// and handles file or data errors appropriately.
void BitcoinExchange::run() {

	std::ifstream btcFile, inputFile;

	if (!openFile(btcFile, DATA_PATH))
		throw BtcError::OpenFile();

	if (!openFile(inputFile, _inputFilePath)) {
		btcFile.close();
		throw BtcError::OpenFile();
	};

	if (!loadBtcDatabase(btcFile)) {
		btcFile.close();
		inputFile.close();
		throw BtcError::Base("Error: Wrong btcDataBate.");
	};

	processTransactions(inputFile);

	btcFile.close();
	inputFile.close();
};