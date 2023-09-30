#ifndef HASHNODE_H
#define HASHNODE_H
#include <iostream>
#include <cstring>

template <typename V>
struct HashNode {
    public:
        HashNode() {
            this->next = nullptr;
            this->key = nullptr;
        }

        HashNode(const char* key, V obj) {
            this->next = nullptr;
            this->key = key;
            this->obj = obj;
        }

        V* search(char* key) {
            if (this->obj == key) {
                return &this->obj;
            }
            else if (this->next != nullptr) {
                return this->next->search(key); 
            }
            return nullptr;
        }

        HashNode* append(const char* key, V& obj) {
            if (this->key == nullptr) {
                this->key = key;
                this->obj = obj;
                return this;
            }

            if (strcmp(this->key, key) == 0) throw "[ERROR] Invalid Argument:  Duplicate Key Detected"; 
            if (this->next != nullptr) return this->next->append(key, obj);
            HashNode* new_node = new HashNode(key, obj);
            this->next = new_node;
            return new_node;
        }

        HashNode* get_next() {
            return this->next;
        }

        HashNode* set_next(HashNode* next) {
            this->next = next;
            return this;
        }

        const char* get_key() const {
            return this->key;
        }

        ~HashNode() {
            if (this->next != nullptr) {
                delete this->next;
            }
        }

    private:
        HashNode* next;
        const char* key;
        V obj;
};

#endif
