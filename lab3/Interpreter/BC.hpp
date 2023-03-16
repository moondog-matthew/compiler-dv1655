#ifndef BC_HPP
#define BC_HPP
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <regex>


using namespace std;


class InstructionBC {
private:
/*
    ID TABLE
    0 : iload n
    1 : iconst v
    2 : istore n
    3 : iadd
    4 : isub
    5 : imul 
    6 : idiv
    7 : igt
    8 : ilt
    9 : ieq
    10 : ior
    11 : iand
    12 : inot
    13 : goto i
    14 : iffalse goto i
    15 : invokevirtual m
    16 : ireturn 
    17 : print
    18 : stop
    19 : label
*/
    int id; // Tells what kind of instruction
    string instruction_argument;  // contains the string with instruction arugments

public: 
    InstructionBC(int _id, string _instruction_argument);
    virtual ~InstructionBC();
    void print(ofstream* outStream) const;
    void stdio_out();
    string& getInstructionArgument();
    int getID(); 
};

class MethodBC {
private:
    vector<string> variables; // used to store variables
    vector<InstructionBC*> instructions;
    string block_name;

public:
    MethodBC(vector<string> &_variables, vector<InstructionBC*> &_instructions, string _block_name);
    MethodBC(string _block_name);
    virtual ~MethodBC();
    void print(ofstream* outStream) const;
    void set_name(string newBlockName);
    string get_name();
    vector<InstructionBC*>& getInstructions();
    void addInstruction(InstructionBC* instr);
};

class ProgramBC {
private:
    // map of qualified method names
        // e.g, Sum.main, Test.sum
    // first string: class name
    // second string: method name 
    vector<pair<string, string>> qual_method_names; 
    vector<MethodBC*> bc_methods;
    MethodBC* currentMethod;
    int index; 

    string first_part_string(string orig);


public:
    ProgramBC();
    virtual ~ProgramBC();
    void print() const;
    void add_method(MethodBC* meth);
    void add_qual_name(pair<string, string> name_pair);
    const vector<MethodBC*>& getBCmethods() const;
    MethodBC* getNextBCmethod();
    void readline(string line);
    MethodBC* getMethodM(string _m);
};


#endif // 