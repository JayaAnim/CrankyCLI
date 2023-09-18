/*
#include <iostream>
#include <map>
#include <vector>
#include "../include/Parser.h"
#include "../include/ArgNode.h"

Parser::Parser() {
    this->head = nullptr;
    this->tail = nullptr;
    this->key = "Uninitialized";
}

Parser::Parser(const char* key) {
    this->head = nullptr;
    this->tail = nullptr;
    this->key = key;
}

ArgNode* Parser::add_argument(const char* key, int n) {
    if (this->head == nullptr) {
        this->head = new ArgNode(key, n);
        this->tail = this->head;
        return head;
    }
    return this->head->append(&tail, key, n); 
}

bool Parser::parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]) {
    if (this->head->parse(hashmap_ref, curr_pos, argc, argv)) {
        //Insert parse options here
    }
    return false;
}

*/
