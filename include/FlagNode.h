/*
#ifndef FLAGNODE_H
#define FLAGNODE_H
#include <map>
#include <vector>

struct FlagNode {
    FlagNode(); //  Used for creation of head node, reserves "--headflagnode" flag
    FlagNode(const char* flag, char* index_flag); // Used for creation of head flagnode
    FlagNode* insert(const char* verbose_flag, const char* alias_flag); // has_alias is by default false, returns pointer to main node inserted (not alias node)
    FlagNode* insert_helper(const char* flag, char* index_flag); 
    FlagNode* search(char* flag);
    bool parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]);
    ~FlagNode();
    FlagNode* left_node;
    FlagNode* right_node;
    const char* flag = nullptr; 
    char* index_flag = nullptr; 
};

#endif
*/
