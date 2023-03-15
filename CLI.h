//
// Created by apple on 15.03.23.
//

#ifndef TASK2_CLI_H
#define TASK2_CLI_H

#include "Root.h"

namespace Task2 {


    class CLI {
    public:
        explicit CLI(Root root);
        void start();

        virtual ~CLI();

        void printAll();

    private:
        void printCLass(int id);
        void printNameSpace(int id);
    private:
        const string tab;
        Root root;
    };

} // Task2

#endif //TASK2_CLI_H
