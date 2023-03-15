//
// Created by apple on 12.03.23.
//

#ifndef TASK2_MYCLASS_H
#define TASK2_MYCLASS_H

#include "MyClassForPoly.h"
#include "MyInterface.h"

namespace Task2 {

    class MyClass : public MyClassForPoly {
    public:
        MyClass(const string &name, const vector<string> &funcVector);

        MyClass(const string &name, const vector<string> &funcVector, const vector<string> &fieldVector);

        MyClass(const string &name, const vector<string> &funcVector, const vector<MyClass> &extendsVector,
                const vector<MyInterface> &implementsVector, const vector<string> &fieldVector);


        const vector<string> &getFieldVector() const override;




        bool implement(const MyInterface& myInterface);

        bool canImplement(const MyInterface& myInterface);

        bool deleteImplement(int id);

        bool extend(const MyClass& myClass);
        bool canExtend(const MyClass& myClass);
        bool deleteExtend(int id);

        void addField(string field) override;

        bool rmField(int id) override;

        bool getField(int id) override;

        bool changeField(string newName, int id) override;

        ~MyClass() override;

    protected:
        vector<MyClass> extendsVector;
        vector<MyInterface> implementsVector;
        vector<string> fieldVector;
    };

} // Task2

#endif //TASK2_MYCLASS_H
