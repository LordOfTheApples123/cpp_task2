//
// Created by apple on 15.03.23.
//

#ifndef TASK2_ROOT_H
#define TASK2_ROOT_H

#include "Namespace.h"

namespace Task2 {


    class Root {
        bool deleteNS(int id);

        bool checkId(int id);
    private:
        vector<Namespace> nsVector;
    public:
        Root();

        void print();

        virtual ~Root();

        void createNS(const string& name);

        Namespace& getNS(int id);
    };

} // Task2

#endif //TASK2_ROOT_H
