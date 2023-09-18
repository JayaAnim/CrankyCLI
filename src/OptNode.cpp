#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "../include/OptNode.h"



OptNode::OptNode() {
    this->left_node = nullptr;
    this->right_node = nullptr;
    this->key = "--headoptionnode"; // This flagname is reservered for head node
}

OptNode::OptNode(const char* key) {
    this->left_node = nullptr;
    this->right_node = nullptr;
    if (sizeof(key) < 3 || (key[0] != '-' && key[1] != '-' && key[2] == '-')) {
        throw "[ERROR] Invalid Option: Options and flags must be --<option/flag name>"; 
    }
    this->key = key;
}

OptNode* OptNode::insert(const char* key) {
    if (strcmp(this->key, key) < 0) {
        if (this->left_node == nullptr) {
            this->left_node = new OptNode(key);
            return this->left_node;
        }
        return this->left_node->insert(key);
    }
    else if (strcmp(this->key, key) > 0) {
        if (this->right_node == nullptr) {
            this->right_node = new OptNode(key);
            return this->right_node;
        }
        return this->right_node->insert(key);
    }
    throw "[ERROR] Duplicate Option: Option has already been added"; 
    return nullptr;
}

OptNode* OptNode::search(char* key) {
    if (strcmp(this->key, key) < 0) {
        if (this->left_node == nullptr) return nullptr;
        return this->left_node->search(key); 
    }
    else if (strcmp(this->key, key) > 0) {
        if (this->right_node == nullptr) return nullptr;
        return this->right_node->search(key);
    }
    return this;
}

bool OptNode::is_valid(char* arg) {
    return true;
}

bool OptNode::parse(std::map<const char*, std::vector<const char*>> &hashmap_ref, int &curr_pos, int argc, char* argv[]) {
    for (; curr_pos < argc; curr_pos++) {
        OptNode* node = search(argv[curr_pos]);        
        //Does not return false because next argv might be flag (flagnode will decide next)
        if (node == nullptr) return false;

        //if (hashmap_ref[argv[curr_pos]].size() > 0) return false;
        //If no argv exists next return false
        else if (++curr_pos == argc) return false;
        //If argv exists next and is not valid return false
        else if (!node->is_valid(argv[curr_pos])) return false;

        char* hash_key = new char[sizeof(node->key) - 2];
        strncpy(hash_key, node->key + 2, sizeof(node->key) -2);
        hashmap_ref[hash_key].push_back(argv[curr_pos]);

        //If option has already been added return false because options can only be added once
        if (hashmap_ref.at(hash_key).size() > 1) return false;
    }
    return true;
}

OptNode::~OptNode() {
    std::cout << "Deleting node: " << this->key << std::endl;
    if (this->left_node != nullptr) delete this->left_node;
    if (this->right_node != nullptr) delete this->right_node;
}
