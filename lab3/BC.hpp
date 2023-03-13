#ifndef BC_HPP
#define BC_HPP
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>

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
*/
    int id; // Tells what kind of instruction
    string instruction_argument;  // contains the string with instruction arugments

public: 
    InstructionBC(int _id, string _instruction_argument);
    virtual ~InstructionBC();
    void print(ofstream* outStream) const;
};

class MethodBC {
private:
    vector<string> variables;
    vector<InstructionBC*> instructions;
    string block_name;

public:
    MethodBC(vector<string> &_variables, vector<InstructionBC*> &_instructions, string _block_name);
    virtual ~MethodBC();
    void print(ofstream* outStream) const;
};

class ProgramBC {
private:
    // map of qualified method names
        // e.g, Sum.main, Test.sum
    // first string: class name
    // second string: method name 
    vector<pair<string, string>> qual_method_names; 
    vector<MethodBC*> bc_methods;

public:
    ProgramBC();
    virtual ~ProgramBC();
    void print() const;
    void add_method(MethodBC* meth);
    void add_qual_name(pair<string, string> name_pair);
};


#endif // 