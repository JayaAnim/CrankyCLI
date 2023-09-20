#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "../include/OptNode.h"

OptNode::OptNode() {
    this->n = 0;
    this->opt = nullptr;
}

OptNode::OptNode(const char* opt, int n) {
    if (strlen(opt) < 4 || opt[0] != '-' || opt[1] != '-' || opt[2] == '-') {
        throw "[ERROR] Invalid Option: Option Format is --<Option Name>";
    } 

    this->n = n;
    this->opt = new char[strlen(opt) -1];
    strcpy(this->opt, opt + 2); 
}

OptNode::OptNode(const OptNode& node) {
    this->opt = new char[strlen(node.get_opt()) + 1];
    strcpy(this->opt, node.get_opt());
    this->n = node.get_n();
}

OptNode& OptNode::operator=(const OptNode& node) {
    if (this == &node) return *this;
    if (this->opt != nullptr) delete[] this->opt;
    this->opt = new char[strlen(node.get_opt()) + 1];
    strcpy(this->opt, node.get_opt());
    this->n = node.get_n();
    return *this;
}

bool OptNode::operator==(char* opt) const {
    if (strcmp(this->opt, opt) == 0) return true;
    return false;
}
                              
bool OptNode::is_valid(char* argv) {
    return true;
}

void OptNode::validate_alias(const char* opt) {
    if (strlen(opt) != 2 || opt[0] != '-' || opt[1] == '-') {
        throw "[ERROR] Invalid Alias: Alias Format is --<Option Name>";
    }
}

char* OptNode::get_opt() const {
    return this->opt;
}

int OptNode::get_n() const {
    return this->n;
}

OptNode::~OptNode() {
    if (this->opt != nullptr) {
        delete this->opt;
    }
}
