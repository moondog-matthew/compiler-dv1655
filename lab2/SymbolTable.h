#ifndef ST_HPP
#define ST_HPP

#include "Node.h"
#include <vector>
class ST {
private:
    std::vector<std::string> stack;

public:

    // should the ST get populated in the constructor? If call populate_ST from here
    ST() = default; 
    ~ST() = default;

    /*
        Suggested operations from PPT
    */
    void enter_scope() {}; // start/push a new nested scope
    void exit_scope() {}; // exist/pop the curent scope
    void add_symbol() {}; // push X to the stack
    bool find_symbol() {}; // search stack for x. return false (0) if not found and true (1) if found
    bool check_scope() {}; // returns true if x is defined in current scope
    void remove_symbol() {}; // pop the stack

    /*
        Mandatory for the assignment
    */
    void populate_ST() {}; // Populate the ST by performing a single left-to-right traversal of the AST?
    void print_ST() {}; // Print symboltable
    // virtual void left_right_traversal() {}; // traverse the AST

};

#endif // ST_HPP<s