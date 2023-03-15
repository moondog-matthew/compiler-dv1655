#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "BC.hpp"
#include <regex>

class Activation {
private:
    int pc;
    /*
        Map : local_variable_values
            string : variable_name
            int : its value  (only int is supported in our compiler)
        OBS! 
            map keys must be unique, otherwise they are overwritten
    */
    map<string, int> local_variable_values; 
    MethodBC* method;
    int index;

public:
    Activation(MethodBC* _method);
    ~Activation() = default;
    /* Getter and setters */
    int getPC() const;
    map<string, int>& getLocalVar();
    MethodBC* getMethod() const;
    /*Functionality*/
    InstructionBC* getNextInstruction();
    void addVariable(string variable_name, int i = 0);
    void updateVariable(string variable_name, int newval);
    int getLocalValue(string key);
    bool varExists(string key);
    int findLabel(string label);
    void setIndex(int _index);
};

class Interpreter {
private:
    ProgramBC* pbc;
    MethodBC* main;
    /*Helper functions*/
    void assignMain();
    string second_half_string(string orig);
    vector<int> data_stack; 
    vector<Activation*> activation_stack;

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