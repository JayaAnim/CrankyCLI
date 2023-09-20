#include <iostream>
#include <cstring>
#include "../include/NameNode.h"


NameNode::NameNode() {
    this->val = nullptr; 
    this->next = nullptr;
}

NameNode::NameNode(char* val) {
    this->val = new char[strlen(val) + 1];
    strcpy(this->val, val);
    this->next = nullptr;
}

NameNode* NameNode::append(NameNode** tail, char* val) {
    NameNode* new_node = new NameNode(val);
    (*tail)->next = new_node;
    (*tail) = new_node;
    return new_node;
}

NameNode::~NameNode() {
    if (this->val != nullptr) delete this->val;
    if (this->next) delete next;
}
