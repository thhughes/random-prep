//
//  linked-list-stack.cpp
//  dsr
//


#include "linked-list-stack.h"

using namespace DataStructures;

bool LinkedListStack::push(DataStructures::Typ inp) {

    LinkedItem* li = new LinkedItem;
    if (nullptr == li) {
        return false;
    }
    li->t = inp;
    
    if (nullptr == Head) {
        Head = li;
        return true;
    }
    
    li->nxt = Head;
    Head = li;
    return true;
}

DataStructures::Typ LinkedListStack::pop() {
    
    if (nullptr == Head) {
        return EmptyContainer;
    }
    
    LinkedItem* tmp = Head;
    Head = Head->nxt;
    
    Typ ret = tmp->t;
    delete tmp;
    
    return ret;
}

DataStructures::Typ LinkedListStack::peek() {
    if (nullptr == Head) {
        return EmptyContainer;
    }
    Typ ret = Head->t;
    return ret;
}

bool LinkedListStack::isEmpty() {
    return Head == nullptr;
}

void LinkedListStack::clear() {
    while (false == isEmpty()) {
        pop();
    }
}


