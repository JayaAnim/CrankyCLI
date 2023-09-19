#ifndef OPTNODE_H
#define OPTNODE_H
#include <cstring>
#include <vector>
#include <map>

struct OptNode {
    OptNode(); // Used for creation of head node, reservers "--headoptionnode" flag name
    OptNode(const char* opt);
    bool is_valid(char* argv);
    ~OptNode();
    OptNode* left_node;
    OptNode* right_node;
    const char* opt = nullptr;
    char* index_opt = nullptr;
};

#endif
