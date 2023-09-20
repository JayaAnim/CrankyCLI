#include <iostream>
#include <cstring>
#include "../include/NameSpace.h"
#include "../include/NameNode.h"

NameSpace::NameSpace() {
    this->key = new char[18];
    strcpy(this->key, "headnamespacenode");
    this->head = nullptr;
    this->tail = nullptr;
    this->left_node = nullptr;
    this->right_node = nullptr;
}

NameSpace::NameSpace(char* key, char* val) {
    this->key = new char[strlen(key) + 1];
    strcpy(this->key, key);
    this->head = new NameNode(val);
    this->tail = this->head;
    this->left_node = nullptr;
    this->right_node = nullptr;   
}

bool NameSpace::insert(char* key, char* val) {
    if (strcmp(this->key, key) < 0) {
        if (this->left_node == nullptr) {
            NameSpace* new_node = new NameSpace(key, val);
            this->left_node = new_node;
            return false;
        }
        return this->left_node->insert(key, val);  
    }
    else if (strcmp(this->key, key) > 0) {
        if (this->right_node == nullptr) {
            NameSpace* new_node = new NameSpace(key, val);
            this->right_node = new_node;
            return false;
        }
        return this->right_node->insert(key, val);
    }
    this->head->append(&this->tail, val);
    return true;
}

NameNode* NameSpace::search(const char* key) {
    if (strcmp(this->key, key) < 0) {
        if (this->left_node == nullptr) {
            return nullptr;
        }
        return this->left_node->search(key);  
    }
    else if (strcmp(this->key, key) > 0) {
        if (this->right_node == nullptr) {
            return nullptr;
        }
        return this->right_node->search(key);
    }
    return this->head;
}

void NameSpace::print() {
    std::cout << this->key << ":\t";
    if (this->head != nullptr) this->head->print();
    std::cout << std::endl;
    if (this->left_node != nullptr) this->left_node->print();
    if (this->right_node != nullptr) this->right_node->print();
}

NameSpace::~NameSpace() {
    if (this->key != nullptr) delete  this->key;
    if (this->head != nullptr) delete this->head;
    if (this->left_node != nullptr) delete this->left_node;
    if (this->right_node != nullptr) delete this->left_node;
}
