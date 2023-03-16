#include <iostream>
#include <fstream>
#include "Interpreter.hpp"

int main(int argc, char **argv)
{
    ProgramBC* progbc;
    Interpreter* inter;
    /*Open file*/
    if(argc > 1) {
        string inputfile = string(argv[1]);
        ifstream programFile (inputfile);
        if (programFile.is_open()) {
        /*
            1. Create ProgramBC
            2. for every line create a InstructionBC
            3. If methodlabel, i.e, does not start with Block_*
                2.1 Create new MethodBC
            
        */
            progbc = new ProgramBC();
            string line;
            while(getline(programFile, line)) {
                progbc->readline(line);
            }
            programFile.close();
            inter = new Interpreter(progbc);
            inter->execute();
            
        }

    }

}