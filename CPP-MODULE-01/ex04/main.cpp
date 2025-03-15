#include <iostream>
#include <fstream>
#include <string>
#include <string.h>


int open_file(const std::string& name, std::ifstream& file) {
	file.open(name);

	if (!file.is_open()) {
		std::cerr << "Error opening file" << std::endl;
		return -1;
	}

	return 0;
}

std::string get_replace_file(char *argv) {
	
	std::string file;

	file = argv;
	file.append(".replace");
	return file;
}

void write_replace_line(std::string& line, const char *to_find, const char *to_replace) {
	
	size_t	position = 0;
	size_t	find_len = strlen(to_find);

	while ((position = line.find(to_find)) != std::string::npos) {
		line.erase(position, find_len);
		line.insert(position, to_replace);
	}
}

int main(int argc, char *argv[]) {
	
	std::ifstream 	fd;
	std::ofstream 	fd_replace;
	std::string		file_name, line;


	if (argc != 4)
		return 1;

	if (open_file(argv[1], fd))
		return 1;
	file_name = get_replace_file(argv[1]);

	std::ofstream  file(file_name);

	while (getline(fd, line)) {
		write_replace_line(line, argv[2], argv[3]);
		file << line << std::endl;
	}
	fd.close();
	fd_replace.close();
	
	return 0;
}
