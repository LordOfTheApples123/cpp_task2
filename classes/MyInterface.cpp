//
// Created by apple on 12.03.23.
//

#include <algorithm>
#include <iostream>
#include "MyInterface.h"
using namespace std;

namespace Task2 {


     const string &MyInterface::getName() const {
        return name;
    }

    MyInterface::MyInterface(const string &name, const vector<string> &funcVector): MyClassForPoly(name, funcVector) {
        this -> name = "interface " + name;
        this -> funcVector = funcVector;

    }

    const vector<MyInterface> &MyInterface::getExtendsVector() const {
        return extendsVector;
    }

    void MyInterface::setExtendsVector(const vector<MyInterface> &extendsVector) {
        MyInterface::extendsVector = extendsVector;
    }

    MyInterface::MyInterface(const string &name, const vector<string> &funcVector,
                             const vector<MyInterface> &extendsVector) : MyClassForPoly(name, funcVector),
                                                                         extendsVector(extendsVector) {
         this -> name = "interface " + name;
     }

    bool MyInterface::canExtendInterface(const MyInterface& anInterface) {
        vector<string> thisFuncs(this->getFuncVector().begin(), this->getFuncVector().end());
        vector<string> extendFuncs(anInterface .getFuncVector().begin(), anInterface.getFuncVector().end());
        sort(thisFuncs.begin(), thisFuncs.end());
        sort(extendFuncs.begin(), extendFuncs.end());
        bool res = std::includes(thisFuncs.begin(), thisFuncs.end(), extendFuncs.begin(), extendFuncs.end());
        thisFuncs.clear();
        thisFuncs.shrink_to_fit();
        extendFuncs.clear();
        extendFuncs.shrink_to_fit();
        return res;
    }

    bool MyInterface::extend(const MyInterface &myInterface) {
        if(canExtendInterface(myInterface)){
            extendsVector.emplace_back(myInterface);
            return true;
        }
        return false;
    }

    bool MyInterface::deleteExtend(int id) {
         if(id >= funcVector.size() || id <0){
             return false;
         }
        funcVector.erase(funcVector.begin() + id);
        return true;
    }

    MyInterface::~MyInterface() {
        extendsVector.clear();
        extendsVector.shrink_to_fit();
    }

    void MyInterface::print() {
        int i = 0;
        cout<<name<<endl;
        cout<< "   funcs: " << endl;
        for(auto it = funcVector.begin(); it!=funcVector.end(); ++it, ++i){
            cout<< "      "<<i<<": ";
            cout << *it<< endl;
        }
    }


} // Task2