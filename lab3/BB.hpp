#ifndef BB_HPP
#define BB_HPP


#include "Tac.hpp"
#include <vector>
#include <fstream>

using namespace std;



class BB {
private: 
    std::string name;
    std::vector<Tac*> tac_instructions;
    Tac* condition;
    BB* false_exit;
    BB* true_exit;
    BB* jumpBlock;
    int id;
    /*Help functions*/
    void generate_BB_content(int &count, ofstream *outStream);

public:
    BB();
    ~BB();

    /* Getters and setters */
    string& getName();
    std::vector<Tac*>& getInstructions();
    Tac* getCondition();
    BB* getFalse();
    BB*  getTrue();
    void setFalse(BB* falseChild);
    void setTrue(BB* trueChild);

    void add_Tac(Tac* tac);
    void generate_BB();
    string generate_name() const;


};

#endif // BB_HPP