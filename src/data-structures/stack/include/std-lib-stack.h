//
//  std-lib-stack.h
//  dsr
//

#pragma once


#include "stack.h"
#include <vector>

namespace DataStructures {

class StdLibStack:  public Stack {
public:
    ~StdLibStack(){}
    
    virtual bool push(Typ inp);
    virtual Typ pop();
    virtual Typ peek();
    virtual bool isEmpty();
    virtual void clear(); 
protected:
    std::vector<Typ> vec;
};

}

