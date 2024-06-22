//
//  linked-list-stack.h
//  dsr
//

#pragma once
#include "stack.h"

namespace DataStructures {

class LinkedListStack : public Stack {
public:
    
    bool push(Typ inp);
    Typ pop();
    Typ peek();
    bool isEmpty();
    void clear();
    
protected:
    struct LinkedItem {
        Typ t;
        LinkedItem* nxt = nullptr;
    };
    
    LinkedItem* Head = nullptr;
};

}
