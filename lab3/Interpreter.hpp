#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "BC.hpp"
#include <regex>

class Activation {
private:
    int pc;
    vector<string> local_variable_values;
    MethodBC* method;

public:
    Activation();
    ~Activation() = default;
    /* Getter and setters */
    int getPC() const;
    vector<string>& getLocalVar();
    MethodBC* getMethod() const;
    InstructionBC* getNextInstruction() const;
};

class Interpreter {
private:
    ProgramBC* pbc;
    MethodBC* main;
    /*Helper functions*/
    void assignMain();

public:
    Interpreter(ProgramBC* _pbc);
    ~Interpreter() = default;
    /* Getter and setters */
    ProgramBC* getPBC() const;
    MethodBC* getMain() const;
    /*Functionality*/
    void execute(); 

};

#endif; // INTERPRETER_HPP