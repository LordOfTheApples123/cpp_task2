//
// Created by apple on 15.03.23.
//

#include "CLI.h"

#include <utility>

namespace Task2 {
    CLI::CLI(Root root) : root(root),  tab("   ") {}

    CLI::~CLI() {

    }

    void CLI::start() {

    }

    void CLI::printAll() {
        root.print();
    }


} // Task2