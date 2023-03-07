#ifndef CFG_HPP
#define CFG_HPP
#include "BB.hpp"

class CFG {
private: 
    BB* entry;

public:
    CFG();
    CFG(Node* node);
    void populate_CFG(Node* node);
    void print_CFG();

};


#endif // CFG_HPP