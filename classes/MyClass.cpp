//
// Created by apple on 12.03.23.
//

#include <algorithm>
#include <iostream>
#include "MyClass.h"

namespace Task2 {
    MyClass::MyClass(const string &name, const vector<string> &funcVector) : MyClassForPoly(name,
                                                                                            funcVector) {
        this->name = "class " + name;
    }

    const vector<string> &MyClass::getFieldVector() const {
        return fieldVector;
    }

    bool MyClass::implement(const MyInterface &myInterface) {
        if (canImplement(myInterface)) {
            implementsVector.emplace_back(myInterface);
            return true;
        }
        return false;
    }

    bool MyClass::canImplement(const MyInterface &myInterface) {
        vector<string> thisFuncs(this->getFuncVector().begin(), this->getFuncVector().end());
        vector<string> extendFuncs(myInterface.getFuncVector().begin(), myInterface.getFuncVector().end());
        sort(thisFuncs.begin(), thisFuncs.end());
        sort(extendFuncs.begin(), extendFuncs.end());
        bool res = std::includes(thisFuncs.begin(), thisFuncs.end(), extendFuncs.begin(), extendFuncs.end());
        thisFuncs.clear();
        thisFuncs.shrink_to_fit();
        extendFuncs.clear();
        extendFuncs.shrink_to_fit();
        return res;
    }

    bool MyClass::deleteImplement(int id) {
        if (id >= implementsVector.size() || id < 0) {
            return false;
        }
        implementsVector.erase(implementsVector.begin() + id);
        return true;
    }

    MyClass::MyClass(const string &name, const vector<string> &funcVector, const vector<string> &fieldVector)
            : MyClassForPoly(name, funcVector), fieldVector(fieldVector) {
        this->name = "class " + name;
    }

    MyClass::MyClass(const string &name, const vector<string> &funcVector, const vector<MyClass> &extendsVector,
                     const vector<MyInterface> &implementsVector, const vector<string> &fieldVector) : MyClassForPoly(
            name, funcVector), extendsVector(extendsVector), implementsVector(implementsVector), fieldVector(
            fieldVector) {
        this->name = "class " + name;
    }

    MyClass::~MyClass() {
        fieldVector.clear();
        fieldVector.shrink_to_fit();
        implementsVector.clear();
        implementsVector.shrink_to_fit();
        extendsVector.clear();
        extendsVector.shrink_to_fit();
    }

    bool MyClass::canExtend(const MyClass &myClass) {
        vector<string> thisFuncs(this->getFuncVector().begin(), this->getFuncVector().end());
        vector<string> extendFuncs(myClass.getFuncVector().begin(), myClass.getFuncVector().end());
        sort(thisFuncs.begin(), thisFuncs.end());
        sort(extendFuncs.begin(), extendFuncs.end());
        bool res = std::includes(thisFuncs.begin(), thisFuncs.end(), extendFuncs.begin(), extendFuncs.end());
        thisFuncs.clear();
        thisFuncs.shrink_to_fit();
        extendFuncs.clear();
        extendFuncs.shrink_to_fit();
        vector<string> thisFields(this->getFieldVector().begin(), this->getFieldVector().end());
        vector<string> extendFields(myClass.getFieldVector().begin(), myClass.getFieldVector().end());
        sort(thisFields.begin(), thisFields.end());
        sort(extendFields.begin(), extendFuncs.end());
        res &= includes(thisFuncs.begin(), thisFuncs.end(), extendFuncs.begin(), extendFuncs.end());
        return res;

    }

    bool MyClass::extend(const MyClass &myClass) {
        if (!canExtend(myClass)) {
            return false;
        }
        extendsVector.emplace_back(myClass);
        return true;
    }

    bool MyClass::deleteExtend(int id) {
        if (id >= extendsVector.size() || id < 0) {
            return false;
        }
        extendsVector.erase(extendsVector.begin() + id);
        return true;
    }

    void MyClass::addField(string field) {
        fieldVector.emplace_back((field));
    }

    bool MyClass::rmField(int id) {
        if (id >= fieldVector.size() || id < 0) {
            return false;
        }
        fieldVector.erase(fieldVector.begin() + id);
        return true;
    }


    bool MyClass::changeField(string newName, int id) {
        if (id >= fieldVector.size() || id < 0) {
            return false;
        }
        fieldVector[id] = std::move(newName);
        return true;
    }

    bool MyClass::getField(int id) {
        false;
    }

    void MyClass::print() {

        int i = 0;
        cout << name << endl;
        cout<< "   funcs: " << endl;
        for (auto it = funcVector.begin(); it != funcVector.end(); ++it, ++i) {
            cout << "      " << i << ": ";
            cout << *it << endl;
        }
        i = 0;
        cout<< "   fields: " << endl;
        for (auto it = fieldVector.begin(); it != fieldVector.end(); ++it, ++i) {
            cout << "      " << i << ": ";
            cout << *it << endl;
        }
        i = 0;
        cout<< "   implements: " << endl;
        for (auto it = implementsVector.begin(); it != implementsVector.end(); ++it, ++i) {
            cout << "      " << i << ": ";
            cout << it->getName() << endl;
        }

    }
} // Task2