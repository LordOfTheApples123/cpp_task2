//
// Created by apple on 12.03.23.
//

#ifndef TASK2_MYCLASSFORPOLY_H
#define TASK2_MYCLASSFORPOLY_H
#include <string>
#include <vector>
using namespace std;

namespace Task2 {

    class MyClassForPoly {

    public:
        virtual const vector<string> &getFuncVector() const;

        void setFuncVector(const vector<string> &functionVector);

        virtual const string &getName() const;

        void setName(const string &name);



        virtual void setFieldVector() const;

        void addFunc(string newFunc);
        virtual bool rmFunc(int id);

        virtual void addField(string field);
        virtual bool rmField(int id);
        virtual bool getField(int id);
        virtual bool changeField(string newName, int id);
        virtual bool changeFunc(string newName, int id);

        bool operator==(const MyClassForPoly &rhs) const;

        bool operator!=(const MyClassForPoly &rhs) const;

        MyClassForPoly(string name, const vector<string> &funcVector);

        virtual ~MyClassForPoly();

        virtual void print();

    protected:
        string name;
        vector<string> funcVector;
    };

} // Task2

#endif //TASK2_MYCLASSFORPOLY_H
