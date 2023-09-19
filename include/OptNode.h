#ifndef OPTNODE_H
#define OPTNODE_H
#include <cstring>
#include <vector>
#include <map>

struct OptNode {
    OptNode(); // Used for creation of head node, reservers "--headoptionnode" flag name
    OptNode(const char* opt, char* index_opt);
    OptNode* insert(const char* opt);
    OptNode* insert_helper(const char* opt, char* index_opt);
    OptNode* search(char* opt);
    bool is_valid(char* arg);
    bool parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]);
    ~OptNode();
    OptNode* left_node;
    OptNode* right_node;
    const char* opt = nullptr;
    char* index_opt = nullptr;
};

#endif
