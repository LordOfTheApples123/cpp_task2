//
// Created by apple on 15.03.23.
//

#ifndef TASK2_ROOT_H
#define TASK2_ROOT_H

#include "Namespace.h"

namespace Task2 {

    class Root {
        void createNS(string name);
        bool deleteNS(int id);
        Namespace& getNS(int id);
    private:
        vector<Namespace> nsVector;
    };

} // Task2

#endif //TASK2_ROOT_H
