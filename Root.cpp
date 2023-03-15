//
// Created by apple on 15.03.23.
//

#include <iostream>
#include "Root.h"
using namespace std;

namespace Task2 {
    void Root::createNS(const string& name) {
         Namespace *ns = new Namespace(name);
         nsVector.emplace_back(*ns);
    }

    Namespace &Root::getNS(int id) {
        return nsVector[id];
    }

    bool Root::deleteNS(int id) {
        if(!checkId(id)){
            return false;
        }
        else return true;
    }

    bool Root::checkId(int id) {
        return id<nsVector.size() && id >0;
    }

    void Root::print(){
        int i = 0;
        for(auto it = nsVector.begin(); it!= nsVector.end(); ++it, ++i){
            Namespace& curr = dynamic_cast<Namespace&>(*it);
            cout<< i << ": ";
            curr.print();
        }
    }

    Root::Root() {}

    Root::~Root() {
        nsVector.clear();
        nsVector.shrink_to_fit();
    }
} // Task2