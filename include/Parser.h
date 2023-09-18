/*
#ifndef PARSER_H
#define PARSER_H
#include "../include/ArgNode.h"

class Parser {
    public:
        Parser();
        Parser(const char* key);
        ArgNode* add_argument(const char* key, int n);
        bool parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]);
    private:
        ArgNode* head;
        ArgNode* tail;
        const char* key;
};

#endif
*/
