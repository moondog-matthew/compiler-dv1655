#include "symbolTable.cpp"

int main() {
    variableRecord* var1 = new variableRecord("var1", "int");
    variableRecord* var2 = new variableRecord("var2", "int");
    variableRecord* var3 = new variableRecord("var3", "int");
    variableRecord* var4 = new variableRecord("var4", "int");
    methodRecord* meth1 = new methodRecord("meth1", "int");
    
    meth1->addVariable("var1", var1);
    meth1->addParameter(var1);

    classRecord* Class1 = new classRecord("Class1", "string");
    // cout << Class1->printRecord() << endl;
    // Class1->addMethod("meth1", meth1);
    // Class1->addVariable("var1", var1);

    // cout << meth1->printRecord() << endl;
    // variableRecord* varLookup = Class1->lookupVariable("variable1");
    // methodRecord* methLookup = Class1->lookupMethod("method1");
    // varLookup = meth1->lookupVariable("kalas");

    // if (methLookup != nullptr) {
    //     cout << methLookup->printRecord() << endl;
    // }

    Scope* scope1 = new Scope(nullptr);

    scope1->addRecord(Class1);
    scope1->addRecord(meth1);
    
    Scope* scope2 = scope1->nextScope();
    scope2->addRecord(var1);
    Scope* scope3 = scope1->nextScope();
    Scope* scope4 = scope2->nextScope();

    scope3->addRecord(var2);
    scope3->addRecord(var3);
    scope4->addRecord(var4);

    // scope1->printScope();

    Record* recLookup = scope1->lookup("meth1");

    if (recLookup != nullptr) {
        cout << recLookup->printRecord() << endl;
    }

}