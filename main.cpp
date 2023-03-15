#include <iostream>
#include "classes/MyInterface.h"
using namespace std;
using namespace Task2;

int main() {
    vector<string> funcs;
    funcs.emplace_back("1");
    funcs.emplace_back("2");
    funcs.emplace_back("3");
    MyClassForPoly interface = MyInterface("gayporn", funcs);
    cout << interface.getName() << endl;
    int i = 0;
    interface.rmFunc(1);
    interface.addFunc("123");
    interface.addField("adf");
    interface.changeFunc("dskfjlasdjflakdsf", 2);
    vector funcsFinal = interface.getFuncVector();
    for( auto it = funcsFinal.begin(); it != funcsFinal.end(); i++, it++){
        printf("%d", i);
        cout << ": " << *it << endl;
    }
    return 0;
}
