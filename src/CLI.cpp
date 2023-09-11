#include <iostream>
#include "../include/CLI.hpp"

bool CLI::defaultValidate(int next_pos, char* argv[]) {
	std::cout << "Default function validate called" << std::endl;
}
// Default function for execute
void CLI::defaultExecute() {
	std::cout << "Default function execute called" << std::endl;
}
// Default function for help
void CLI::defaultHelp() {
	std::cout << "Default function help called" << std::endl;
}
// Default function for error
bool CLI::defaultError(int code, int next_pos, char* argv[]) {
	std::cout << "Default function error called" << std::endl;
	return false; 
}



