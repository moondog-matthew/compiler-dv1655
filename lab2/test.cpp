#include "symbolTable.cpp"

int main() {
    variableRecord* var1 = new variableRecord("var1", "int");
    methodRecord* meth1 = new methodRecord("meth1", "int");
    
    meth1->addVariable("var1", var1);
    meth1->addParameter(var1);

    classRecord* Class1 = new classRecord("Class1", "string");
    cout << Class1->printRecord() << endl;
    Class1->addMethod("method1", meth1);
    Class1->addVariable("variable1", var1);


    // cout << meth1->printRecord() << endl;
    variableRecord* varLookup = Class1->lookupVariable("variable1");
    methodRecord* methLookup = Class1->lookupMethod("method1");
    // varLookup = meth1->lookupVariable("kalas");

    if (methLookup != nullptr) {
        cout << methLookup->printRecord() << endl;
    }

}