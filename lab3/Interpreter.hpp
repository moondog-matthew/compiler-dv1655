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
    Activation() = default;
    ~Activation() = default;
    /* Getter and setters */
    const int getPC() const;
    const vector<string>& getLocalVar() const;
    const MethodBC* getMethod() const;

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
    const ProgramBC* getPBC() const;
    const MethodBC* getMain() const;
    /*Functionality*/
    void execute(); 

};

#endif; // INTERPRETER_HPP