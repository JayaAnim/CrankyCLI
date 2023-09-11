#include <iostream>
#include "../include/ArgumentNode.hpp"

bool ArgumentNode::run(int next_pos, int argc, char* argv[]) {
	std::cout << "ArgNode running" << std::endl;	
	return true;
};

CLI* ArgumentNode::getLastNode() {
	std::cout << "ArgNode running" << std::endl;	
	return nullptr;
};

CLI* ArgumentNode::navigateBack() {
	std::cout << "ArgNode running" << std::endl;	
	return nullptr;
};

bool addArgNode(char** const name) {
	std::cout << "ArgNode running" << std::endl;	
	return false;
}

bool addCmdNode(char** const name) {
	std::cout << "ArgNode running" << std::endl;	
	return false;
}

void addFlag(const char** name, bool value) {
	std::cout << "ArgNode running" << std::endl;	
}

bool addOption(const char** name, T value) {
	std::cout << "ArgNode running" << std::endl;	
	return false; 
}

private:
const char** name;
CommandNode* next_cmd;
ArgumentNode* next_arg;
std::vector<std::string> flags;
std::vector<Option*> options;
};

class CommandNode : public CLI {
public:
CommandNode(const char** name) {
	this->name = name;
}

// Implement your methods and members here
};

template <typename T> class Option {
public:
Option(const char** name, T& value) {
	this->name = name;
	this->value = value;
}

// Implement your methods and members here
private:
const char** name;
T value;
int (*validate)(int next_);
int (*convert)();
};


