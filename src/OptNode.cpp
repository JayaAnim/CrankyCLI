#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "../include/OptNode.h"



OptNode::OptNode() {
    this->left_node = nullptr;
    this->right_node = nullptr;
    this->opt = "headoptionnode"; // This flagname is reservered for head node
}

OptNode::OptNode(const char* opt, char* index_opt) {
    this->left_node = nullptr;
    this->right_node = nullptr;
    this->opt = opt;
    this->index_opt = index_opt;
}

OptNode* OptNode::insert(const char* opt) {
    if (strlen(opt) < 3 || (opt[0] != '-' || opt[1] != '-' || opt[2] == '-')) {
        throw "[ERROR] Invalid Option: Options and flags must be --<option/flag name>"; 
    }

    char* index_opt = new char[strlen(opt) - 1];
    strcpy(index_opt, opt + 2);

    OptNode* res = insert_helper(opt, index_opt);

    if (res == nullptr) {
        throw "[ERROR] Duplicate Option: Option has already been added"; 
    }

    return res;
}

OptNode* OptNode::insert_helper(const char* opt, char* index_opt) {
    if (strcmp(this->opt, opt) < 0) {
        if (this->left_node == nullptr) {
            this->left_node = new OptNode(opt, index_opt);
            return this->left_node;
        }
        return this->left_node->insert_helper(opt, index_opt);
    }
    else if (strcmp(this->opt, opt) > 0) {
        if (this->right_node == nullptr) {
            this->right_node = new OptNode(opt, index_opt);
            return this->right_node;
        }
        return this->right_node->insert_helper(opt, index_opt);
    }

    throw "[ERROR] Duplicate Option: Option has already been added"; 
    return nullptr;
}

OptNode* OptNode::search(char* opt) {
    if (strcmp(this->opt, opt) < 0) {
        if (this->left_node == nullptr) return nullptr;
        return this->left_node->search(opt); 
    }
    else if (strcmp(this->opt, opt) > 0) {
        if (this->right_node == nullptr) return nullptr;
        return this->right_node->search(opt);
    }
    return this;
}

bool OptNode::is_valid(char* arg) {
    return true;
}

bool OptNode::parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]) {
    for (; curr_pos < argc; curr_pos++) {
        OptNode* node = search(argv[curr_pos]);        
        //Does not return true because next argv might be flag (flagnode will decide next)
        if (node == nullptr) return true;

        //if (hashmap_ref[argv[curr_pos]].size() > 0) return false;
        //If no argv exists next return false
        else if (++curr_pos == argc) return false;
        //If argv exists next and is not valid return false
        else if (!node->is_valid(argv[curr_pos])) return false;

        hashmap_ref[node->index_opt].push_back(argv[curr_pos]);

        //If option has already been added return false because options can only be added once
        if (hashmap_ref.at(node->index_opt).size() > 1) return false;
    }
    return true;
}

OptNode::~OptNode() {
    if (this->index_opt != nullptr) delete []this->index_opt;
    if (this->left_node != nullptr) delete this->left_node;
    if (this->right_node != nullptr) delete this->right_node;
}
