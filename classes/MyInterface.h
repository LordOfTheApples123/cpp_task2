//
// Created by apple on 12.03.23.
//

#ifndef TASK2_MYINTERFACE_H
#define TASK2_MYINTERFACE_H
#include <string>
#include <vector>
#include "MyClassForPoly.h"

using namespace std;

namespace Task2 {

    class MyInterface : public MyClassForPoly{
    public:
        MyInterface(const string &name, const vector<string> &funcVector);

        MyInterface(const string &name, const vector<string> &funcVector, const vector<MyInterface> &extendsVector);

        const vector<MyInterface> &getExtendsVector() const;

        void setExtendsVector(const vector<MyInterface> &extendsVector);

        const string & getName() const override;

        bool extend(const MyInterface& myInterface);

        bool canExtendInterface(const MyInterface& myInterface);

        bool deleteExtend(int id);

        ~MyInterface() override;


        void print() override;

    private:
        vector<MyInterface> extendsVector;

    };

} // Task2

#endif //TASK2_MYINTERFACE_H
