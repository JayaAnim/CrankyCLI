#ifndef FLAGNODE_H
#define FLAGNODE_H
#include <map>
#include <vector>

struct FlagNode {
    FlagNode(); //  Used for creation of head node, reserves "--headflagnode" flag
    FlagNode(const char* flag); // Used for creation of head flagnode
    void insert(const char* verbose_flag, bool has_alias); // has_alias is by default false
    void insert_helper(const char* flag);
    FlagNode* search(char* flag);
    bool parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]);
    ~FlagNode();
    FlagNode* left_node;
    FlagNode* right_node;
    const char* flag; 
    char* alias_flag; 
};

#endif
