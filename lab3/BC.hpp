#ifndef BC_HPP
#define BC_HPP
#include <vector>
#include <string>
#include <map>

using namespace std;

class BC {
public:
    BC() = default;
    virtual ~BC();
    virtual void print() const = 0; // pure virtual
}; 

class InstructionBC : public BC {
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
    12 : goto i
    13 : iffalse goto i
    14 : invokevirtual m
    15 : ireturn 
    16 : print
    17 : stop
*/

    int id; // Tells what kind of argument it is 
    string argument;  // contains the string with instruction and value

public: 
    InstructionBC();
    void print() const override;
};

class MethodBC : public BC {
private:
    vector<string> variables;
    vector<InstructionBC*> instructions;
public:
    MethodBC();
    void print() const override;
};

class ProgramBC : public BC {
private:
    // map of qualified method names
        // e.g, Sum.main, Test.sum
    // first string: class name
    // second string: method name 
    std::map<string, string> qual_method_names; 

public:
    ProgramBC();
    void print() const override;
};

#endif // 