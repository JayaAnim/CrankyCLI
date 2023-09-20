#ifndef OPTNODE_H
#define OPTNODE_H
#include <cstring>
#include <vector>
#include <map>

class OptNode {
    public:
        OptNode();
        OptNode(const char* opt, int n = 0); // base constructor, validates opt param, if n = 0 option is treated as flag, and alias's are allowed 
        OptNode(const OptNode& node); // Copy constructor overload
        OptNode& operator=(const OptNode& node); // Copy assignment overload
        bool operator==(char* opt) const; // Overload comparison operator
        static void validate_alias(const char* opt); // Used to validate alias keys used in hashmap, throws error if invalid
        bool is_valid(char* argv); // validates if received argv is valid opt
        char* get_opt() const;
        int get_n() const;
        ~OptNode(); // destructor
    private:
        int n;
        char* opt;
};

#endif
