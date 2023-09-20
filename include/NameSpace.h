#ifndef NAMESPACE_H
#define NAMESPACE_H
#include "NameNode.h"

struct NameSpace {
        NameSpace(); // Constructs head namespace node
        NameSpace(char* key, char* val); // Constructs new namespace node for insert
        bool insert(char* key, char* val); // Inserts new namespace node into tree, returns true if namespace node already exists there
        NameNode* search(const char* key); // Searches for namespace node with key and returns head NameNode
        void print();
        ~NameSpace();
        NameNode* head;
        NameNode* tail;
        NameSpace* left_node;
        NameSpace* right_node;
        char* key;
};

#endif
