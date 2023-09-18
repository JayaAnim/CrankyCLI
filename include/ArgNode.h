#ifndef ARGNODE_H
#define ARGNODE_H
#include <map>
#include <vector>

struct ArgNode {
    ArgNode(); //Constructs new node
    ArgNode(const char* key, int n); //Constructs new node, used to construct head node
    ArgNode* append(ArgNode** tail, const char* key, int n); //Appends node to end of list, modifies tail pointer to point to new end of list
    /*
     * Will be assignable in the future
    */
    bool is_valid(char* arg); //Checks if current argv at current pos is valid
    /*
     * Parses argv, for matches to argnodes
     * Adds argv into hashmap until n args is reached, a invalid arg is encountered, or an option/flag is found
     * Returns false if error encountered when parsing
    */ 
    bool parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]);  
    ~ArgNode(); // Deletes ArgNode 
    const char* key; //Key of arg at pos
    int n; // Number of related args after expected (64 means until options or end of argv, 64 will only be specified for last arg)
    ArgNode* next_node; // Points to next expected arg
};


#endif
