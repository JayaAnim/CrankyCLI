/*
#ifndef PARSER_H
#define PARSER_H
#include "../include/ArgNode.h"
#include "../include/OptNode.h"
#include "../include/FlagNode.h"

class Parser {
    public:
        Parser();
        Parser(const char* arg);
        ArgNode* add_argument(const char* arg, int n);
        OptNode* add_option(const char* opt);
        bool parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]);
    private:
        ArgNode* arg_head;
        ArgNode* arg_tail;
        OptNode* opt_head;
        FlagNode* flag_head;
        Parser* left_node;
        Parser* right_node;
        const char* arg = nullptr;
};

#endif
*/
