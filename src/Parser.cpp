/*
#include <iostream>
#include <map>
#include <vector>
#include "../include/Parser.h"
#include "../include/ArgNode.h"
#include "../include/OptNode.h"
#include "../include/FlagNode.h"

Parser::Parser() {
    this->arg_head = new ArgNode();
    this->arg_tail = arg_head;
    this->opt_head = new OptNode();
    this->flag_head = new FlagNode();
}

Parser::Parser(const char* arg) {
    this->arg = arg;
}

ArgNode* Parser::add_argument(const char* arg, int n) {
    return this->arg_head->append(&this->arg_tail, arg, n);     
}

bool Parser::parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]) {
    this->
}

*/

