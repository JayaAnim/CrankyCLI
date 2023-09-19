#ifndef HASHNODE_H
#define HASHNODE_H

template <typename V>
class HashNode {
    public:
        HashNode();
        HashNode(const char* key, V* obj);
        V* find(const char* key);
        HashNode* append(const char* key, V obj);
        HashNode* get_next();
        HashNode* set_next(HashNode* next);
        ~HashNode();
    private:
        HashNode* next;
        const char* key;
        V* obj;
};

#endif
