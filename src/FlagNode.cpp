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

FlagNode::FlagNode(const char* flag, char* index_flag) {
    this->flag = flag;
    this->index_flag = index_flag;
    this->left_node = nullptr;
    this->right_node = nullptr;
}

FlagNode* FlagNode::insert(const char* verbose_flag, const char* alias_flag = nullptr) {
    if (strlen(verbose_flag) < 4 || (verbose_flag[0] != '-' && verbose_flag[1] != '-') || verbose_flag[2] == '-') {
        throw "[ERROR] Invalid Flag:  Flags must be --<Flag name>"; 
        return nullptr;
    }
    char* index_flag = new char[strlen(verbose_flag -1)];
    strcpy(index_flag, verbose_flag + 2);
    FlagNode* res = insert_helper(verbose_flag, index_flag);

    if (res == nullptr) {
        throw "[ERROR] Duplicate Flag: Flag has already been added"; 
        return nullptr;
    }

    if (alias_flag == nullptr) return res;

    else if (strlen(alias_flag) > 2 || alias_flag[0] != '-' || alias_flag[1] == '1') {
        throw "[ERROR] Invalid Flag:  Alias flags must be -<letter>"; 
        return nullptr;
    }
    
    index_flag = new char[strlen(verbose_flag -1)];
    strcpy(index_flag, verbose_flag + 2);

    if (insert_helper(alias_flag, index_flag) == nullptr) {
        throw "[ERROR] Duplicate Alias Flag: Alias has already been added";
        return nullptr;
    }

    return res;
}

FlagNode* FlagNode::insert_helper(const char* flag, char* index_flag) {
    if (strcmp(this->flag, flag) < 0) {
        if (this->left_node == nullptr) {

            this->left_node = new FlagNode(flag, index_flag);
            return this->left_node;
        }
        return this->left_node->insert_helper(flag, index_flag);
    }
    else if (strcmp(this->flag, flag) > 0) {
        if (this->right_node == nullptr) {
            this->right_node = new FlagNode(flag, index_flag);
            return this->right_node;
        }
        return this->right_node->insert_helper(flag, index_flag);
    }
    return nullptr;
}

FlagNode* FlagNode::search(char* flag) {
    if (strcmp(this->flag, flag) < 0) {
        if (this->left_node == nullptr) return nullptr;
        return this->left_node->search(flag); 
    }
    else if (strcmp(this->flag, flag) > 0) {
        if (this->right_node == nullptr) return nullptr;
        return this->right_node->search(flag);
    }

    return this;
}

bool FlagNode::parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]) {

    for (; curr_pos < argc; curr_pos++) {
         std::cout << "Searching for " << argv[curr_pos] << std::endl;
               
        FlagNode* node = search(argv[curr_pos]);

        if (node == nullptr) return false;

        hashmap_ref[node->index_flag].push_back(node->index_flag);
        
        //If flag has already been set return false because flags can only be set once
        if (hashmap_ref.at(node->index_flag).size() > 1) return false;
    }
    return true;
}

FlagNode::~FlagNode() {
    if (this->index_flag != nullptr) delete[] this->index_flag;
    if (this->left_node != nullptr) delete this->left_node;
    if (this->right_node != nullptr) delete this->right_node;
}
