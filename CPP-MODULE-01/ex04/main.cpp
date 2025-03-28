#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

void write_replace_line(std::string& line, const char *to_find, const char *to_replace) {
	
	size_t	position = 0;
	size_t	find_len = strlen(to_find);

	while ((position = line.find(to_find)) != std::string::npos) {
		line.erase(position, find_len);
		line.insert(position, to_replace);
	}
}

int main(int argc, char *argv[]) {
	
	std::ifstream 	fd_in;
	std::ofstream 	fd_out;
	std::string		file_name, line;

	if (argc != 4)
		return std::cout << "Not enough parameters!\n", 1;
	fd_in.open(argv[1]);
	if (!fd_in.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return (1);
	}
	file_name = argv[1];
	file_name.append(".replace");

	fd_out.open(file_name.c_str());
	if (!fd_out.is_open())
		return (std::cerr << "Error opening file" << std::endl, 1);
	while (getline(fd_in, line)) {
		write_replace_line(line, argv[2], argv[3]);
		fd_out << line << std::endl;
	}
	fd_in.close();
	fd_out.close();
	
	return 0;
}
