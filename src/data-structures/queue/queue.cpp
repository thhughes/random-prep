//
//  stack.cpp
//  dsr
//

#include "queue.h"



std::unique_ptr<DataStructures::Queue> DataStructures::Queue::Factory(Type t) {
    switch (t) {
        default:
            return nullptr;
    }
}

std::string_view DataStructures::Queue::typeAsStr(Type t) {
    switch (t) {
        case LinkedListQueue: {
            return "Linked List Queue";
        }
        default: {
            return "INVALID_QUEUE";
        }
    }
}
