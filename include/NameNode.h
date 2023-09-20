#ifndef NAMENODE_H
#define NAMENODE_H

class NameNode {
    public:
        NameNode();
        NameNode(char* val);
        NameNode* append(NameNode** tail, char* val);
        ~NameNode();
    private:
        NameNode* next;
        char* val;
};

#endif
