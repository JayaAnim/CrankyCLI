#include <iostream>
#include <map>
#include <vector>
#include "../include/ArgNode.h"

//Constructs new node
ArgNode::ArgNode() {
    this->next_node = nullptr;
}

ArgNode::ArgNode(const char* key, int n) {
    this->key = key;
    this->n = n;
    this->next_node = nullptr;
}

ArgNode* ArgNode::append(ArgNode** tail, const char* key, int n = 1) {
    ArgNode* new_node = new ArgNode();
    new_node->key = key;
    new_node->n = n;
    (*tail)->next_node = new_node;
    (*tail) = new_node;
    return new_node;
}

bool ArgNode::is_valid(char* arg) {
    if (arg[0] != '-') {
        return true;
    }
    else {
        return false;
    }
}

bool ArgNode::parse(std::map<const char*, std::vector<const char*>>& hashmap_ref, int &curr_pos, int argc, char* argv[]) {
    int parsed = 0;
    while (this->n > parsed && argc > curr_pos) {
        if (!is_valid(argv[curr_pos])) {
            return false;  
        }
        hashmap_ref[this->key].push_back(argv[curr_pos]);
        ++curr_pos;
        ++parsed;
    }

    // If number of args parsed didnt match number expected
    if (n != 64 && parsed != n) {
        return false;
    }
    // If number of args parsed was successful and next args exist, parse those
    if (this->next_node != nullptr) {
        return this->next_node->parse(hashmap_ref, curr_pos, argc, argv);
    }
    // If # args is unspecified but next argv exists and isnt an option/flag (this is an error because unspecified args can only be used once and must be at the end of a command)
    if (n == 64 && argc > curr_pos && argv[curr_pos][0] != '-') {
        return false;
    }
    // If arg parse was successful
    return true;
}

ArgNode::~ArgNode() {
    if (this->next_node != nullptr) delete this->next_node;
}
