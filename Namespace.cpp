//
// Created by apple on 12.03.23.
//

#include "Namespace.h"

#include <utility>
#include <algorithm>
using namespace Task2;
using namespace std;


namespace Task2 {


    MyClassForPoly Namespace::rmCLass(int id) {
        MyClassForPoly res = classVector[id];
        classVector.erase(classVector.begin() + id);
        return res;
    }

    void Namespace::addClass(MyClassForPoly myClass) {
        classVector.push_back(myClass);
    }

    Namespace::Namespace(string name, const vector<MyClassForPoly> &classVector) : name(std::move(name)),
                                                                                   classVector(classVector) {}

    Namespace::~Namespace() {
        name.erase();
        classVector.clear();
        classVector.shrink_to_fit();
    }

    bool Namespace::operator==(const Namespace &rhs) const {
        return name == rhs.name;
    }



    bool Namespace::operator!=(const Namespace &rhs) const {
        return rhs.name != this->name;
    }

    MyClassForPoly Namespace::rmClass(MyClassForPoly myClass) {
        if(std::find(classVector.begin(), classVector.end(), myClass) != classVector.end()){

        }
    }

    Namespace::Namespace(string name) : name(std::move(name)) {

    }

    Namespace &Namespace::operator=(const Namespace &rhs) = default;
} // Task2