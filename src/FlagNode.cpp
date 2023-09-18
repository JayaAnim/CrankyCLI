#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include "../include/FlagNode.h"

FlagNode::FlagNode() {
    this->flag = "headflagnode";
    this->left_node = nullptr;
    this->right_node = nullptr;
}

FlagNode::FlagNode(const char* flag) {
    this->flag = flag;
    this->left_node = nullptr;
    this->right_node = nullptr;
}

void FlagNode::insert(const char* verbose_flag, bool has_alias = false) {
    if (sizeof(verbose_flag) < 3 || (verbose_flag[0] != '-' && verbose_flag[1] != '-') || verbose_flag[2] == '-') {
        throw "[ERROR] Invalid Flag:  Flags must be --<Flag name>"; 
    }


}

void FlagNode::insert_helper(const char* flag) {

}
/*
    FlagNode(); // Not used
    FlagNode(const char* flag); // Used for creation of head flagnode
    bool insert(const char* verbose_flag, bool has_alias);
    bool insert_helper(const char* flag);
    FlagNode* search(char* flag);
    bool parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]);
    ~FlagNode();
    FlagNode* left_node;
    FlagNode* right_node;
    const char* flag; 
*/
/*
FlagNode::FlagNode() {
    this->left_node = nullptr;
    this->right_node = nullptr;
}

FlagNode::FlagNode(const char* verbose_flag, bool has_alias = false) {
    this->left_node = nullptr;
    this->right_node = nullptr;
    this->verbose_flag = verbose_flag;
    if (sizeof(verbose_flag) < 4 || (verbose_flag[0] != '-' && verbose_flag[1] != '-' && verbose_flag[2] == '-')) {
        throw "[ERROR] Invalid Flag:  Flags must have verbose name --<Flag Name>, and flag names must be more than 2 characters\nAutomatic creation of alias flag may be specified"; 
    }
    if (alias_flag) {
        this->flag = new char[2];
        this->flag[0] = tolower(verbose_flag[1]);
        this->flag[1] = tolower(verbose_flag[2]);
    }
}

FlagNode* FlagNode::insert(const char* verbose_flag, bool alias_flag) {
    if (strcmp(this->verbose_flag, verbose_flag) < 0) {
        if (this->left_node == nullptr) {
            this->left_node = new FlagNode(verbose_flag, alias_flag);
            return this->left_node;
        }
        return this->left_node->insert(verbose_flag, alias_flag);
    }
    else if (strcmp(this->verbose_flag, verbose_flag) > 0) {
        if (this->right_node == nullptr) {
            this->right_node = new FlagNode(verbose_flag, alias_flag);
            return this->right_node;
        }
        return this->right_node->insert(verbose_flag, alias_flag);
    }
    return nullptr;
}


FlagNode* insert_alias(const char* verbose_flag, char* alias_flag); // Helper function to insert, called if user specifies insertion with alias

FlagNode* FlagNode::search(char* index_flag, char* flag) {
    if (strcmp(this->flag, index_flag) < 0) {
        if (this->left_node == nullptr) return nullptr;
        return this->left_node->search(index_flag, flag); 
    }
    else if (strcmp(this->flag, index_flag) > 0) {
        if (this->right_node == nullptr) return nullptr;
        return this->right_node->search(index_flag, flag);
    }

    //Index flag matched, so if flag len > 2 it is expected to match verbose flag
    if (sizeof(flag) > 2) {
        if (strcmp(flag, this->verbose_flag) == 0) return this;
        return nullptr;
    }
    return this;
}

bool FlagNode::parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]) {

    for (; curr_pos < argc; curr_pos++) {
        FlagNode* node;
        //If argv is too small to be any flag
        if (sizeof(argv[curr_pos]) < 2) return false;
        //If argv could be small flag
        else if (sizeof(argv[curr_pos]) == 2) node = search(argv[curr_pos], argv[curr_pos]);
        //If argv could not be a flag (flags are either 2 chars or >3 chars)
        else if (sizeof(argv[curr_pos]) == 3) return false;
        //If argv must be a verbose flag
        else {
            char* index_flag = new char[2];
            index_flag[0] = argv[curr_pos][0];
            index_flag[1] = argv[curr_pos][2];
            node = search(index_flag, argv[curr_pos]);
        }
        
        if (node == nullptr) return false;

        hashmap_ref[node->verbose_flag].push_back(node->verbose_flag);
        
        //If flag has already been set return false because flags can only be set once
        if (hashmap_ref.at(node->verbose_flag).size() > 1) return false;
    }
    return true;
}

FlagNode::~FlagNode() {
    std::cout << "Deleting node: " << this->verbose_flag << std::endl;
    if (this->left_node != nullptr) delete this->left_node;
    if (this->right_node != nullptr) delete this->right_node;
}
*/
