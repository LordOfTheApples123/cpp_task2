#include <iostream>
#include "classes/MyInterface.h"
#include "Root.h"
#include "classes/MyClass.h"
#include "CLI.h"

using namespace std;
using namespace Task2;

void test1(){
    Root *root = new Root();
    root->createNS("ns1");
    root->createNS("ns2");
    Namespace& ns1 = root->getNS(0);
    Namespace& ns2 = root->getNS(1);
    vector<string> funcs1;
    funcs1.emplace_back("func1");
    funcs1.emplace_back("func2");
    funcs1.emplace_back("func3");
    MyClassForPoly *interface1 = new MyInterface("int1", funcs1);
    ns1.addClass(interface1);
    vector<string> funcs2;
    funcs2.emplace_back("func1");
    funcs2.emplace_back("func2");
    funcs2.emplace_back("func3");
    funcs2.emplace_back("func4");
    vector<string> fields1;
    fields1.emplace_back("field1");
    fields1.emplace_back("field2");
    fields1.emplace_back("field3");
    MyClassForPoly *class1 = new MyClass("cl 1", funcs2, fields1);
    MyClass *cast = dynamic_cast<MyClass*>(class1);
    cast->implement(*dynamic_cast<MyInterface*>(interface1));
    ns1.addClass(class1); //print full tree of classes



    CLI *cli = new CLI(*root);
    cli->printAll();
    //delete field from interface int 1
    Namespace ns = root->getNS(0);
    MyClassForPoly* test1 = ns.get(0);
    auto* myInterface = dynamic_cast<MyInterface*>(test1);
    myInterface->rmFunc(1);
    cout <<endl;
    cout <<"after deleting field: "<< endl;
    cli->printAll();

}

int main() {
    test1();
    //обещаю сделать нормальную консоль к следующей паре
    return 0;
}
