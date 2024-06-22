//
//  stack.h
//

#pragma once
#include "data-structures-shared.h"
#include <memory>
#include <string_view>
#include <cstdint>

namespace DataStructures {
    
class Queue {
public:
    
    enum Type {
        LinkedListQueue,    /* linked-list-queue.h */
        
    };
    static std::string_view typeAsStr(Type t); 
    
    static std::unique_ptr<Queue> Factory(Type t);
    
    virtual ~Queue() { }
    /// @brief Should technically implement all the copy, move, assignment, etc. operators.
    virtual bool enqueue(Typ inp) = 0;
    virtual Typ dequeue() = 0;
    virtual uint32_t size() = 0;
    virtual bool isEmpty() = 0;
    virtual void clear() = 0; 
};







}


