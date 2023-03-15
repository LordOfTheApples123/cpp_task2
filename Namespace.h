//
// Created by apple on 12.03.23.
//

#ifndef TASK2_NAMESPACE_H
#define TASK2_NAMESPACE_H
#include <string>
#include <utility>
#include <vector>
#include "classes/MyClassForPoly.h"

using namespace std;

namespace Task2 {

    class Namespace {
    public:
        Namespace(string name, const vector <MyClassForPoly*> &classVector);

        explicit Namespace(string name);

        ~Namespace();

        bool operator==(const Namespace &rhs) const;

        bool operator!=(const Namespace &rhs) const;

        Namespace& operator=(const Namespace &rhs);

        MyClassForPoly * rmCLass(int id);
        MyClassForPoly * rmClass(MyClassForPoly* myClass);
        void addClass(MyClassForPoly* myClass);
        MyClassForPoly *& get(int id);

        void print();

    private:
        string name;
        vector<MyClassForPoly*> classVector;
    };





}; // Task2

#endif //TASK2_NAMESPACE_H
