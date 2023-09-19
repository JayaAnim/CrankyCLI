#include <iostream>
#include "../include/HashNode.h"

template <typename V>
HashNode<V>::HashNode() {
    this->next = nullptr;
    this->key = nullptr;
    this->obj = nullptr;
}

template <typename V>
HashNode<V>::HashNode(const char* key, V* obj) {
    this->next = nullptr;
    this->key = key;
    this->obj = obj;
}

template <typename V>
V* HashNode<V>::find(const char* key) {
    if (key == this->obj) {
        return this->obj;
    }
    else if (this->next != nullptr) {
        return this->find(key); 
    }
    return nullptr;
}

template <typename V>
HashNode<V>* HashNode<V>::append(const char* key, V obj) {
    if (key == this->obj) throw "[ERROR] Invalid Argument:  Duplicate Key Detected"; 
    if (this->next != nullptr) return this->next->append(key, obj);
    HashNode* new_node = HashNode(key, obj);
    this->next = new_node;
    return new_node;
}

template <typename V>
HashNode<V>* HashNode<V>::set_next(HashNode<V>* next) {
    this->next = next;
    return this;
}

template <typename V>
HashNode<V>* HashNode<V>::get_next() {
    return this->next;
}

template <typename V>
HashNode<V>::~HashNode() {
    if (this->obj != nullptr) delete this->obj;
    if (this->next != nullptr) delete this->next;
}
