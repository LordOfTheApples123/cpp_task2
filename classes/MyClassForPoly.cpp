//
// Created by apple on 12.03.23.
//

#include "MyClassForPoly.h"

#include <utility>
#include <iostream>
using namespace std;

namespace Task2 {


    void MyClassForPoly::setFuncVector(const vector<string> &functionVector) {
        MyClassForPoly::funcVector = functionVector;
    }


    void MyClassForPoly::setName(const string &newName) {
        MyClassForPoly::name = newName;
    }

    const vector<string> &MyClassForPoly::getFuncVector() const {
        return funcVector;
    }

    const string &MyClassForPoly::getName() const {
        return name;
    }

    MyClassForPoly::MyClassForPoly(string name, const vector<string> &funcVector) : name(std::move(name)), funcVector(funcVector) {}

    const vector<string> &MyClassForPoly::getFieldVector() const {
        cout << "no fields";
        return {};
    }

    void MyClassForPoly::setFieldVector() const {
    }

    void MyClassForPoly::addFunc(string newFunc) {
        this->funcVector.push_back(newFunc);
    }

    bool MyClassForPoly::rmFunc(int id) {
        if(id >= funcVector.size() || id < 0){
            return false;
        }
        funcVector.erase(funcVector.begin() + id);
        return true;
    }

    void MyClassForPoly::addField(string field) {
        cout << "this class can't have fields \n";
    }

    bool MyClassForPoly::rmField(int id) {
        cout<< "this class can't have fields \n";
        return false;
    }

    bool MyClassForPoly::getField(int id) {
        cout << "this class can't have fields \n";
        return false;
    }

    bool MyClassForPoly::changeField(string newName, int id) {
        cout << "this class can't have fields \n";
        return false;
    }

    bool MyClassForPoly::changeFunc(string newName, int id) {
        if(id >= funcVector.size() || id<0){
            return false;
        }
        funcVector[id] = std::move(newName);
        return true;
    }

    bool MyClassForPoly::operator==(const MyClassForPoly &rhs) const {
        return name == rhs.name;
    }

    bool MyClassForPoly::operator!=(const MyClassForPoly &rhs) const {
        return name != rhs.name;
    }

     MyClassForPoly::~MyClassForPoly() {
        name.erase();
        funcVector.clear();
        funcVector.shrink_to_fit();
    }


} // Task2