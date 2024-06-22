//
//  std-lib-stack.cpp
//  dsr
//

#include "std-lib-stack.h"
using  namespace DataStructures;

bool StdLibStack::push(Typ inp)
{
    auto len = vec.size();
    vec.push_back(inp);
    return len < vec.size();
}

Typ StdLibStack::pop()
{
    if (vec.empty()) {
        return EmptyContainer;
    }
    auto v = peek();
    vec.pop_back();
    return v;
}

Typ StdLibStack::peek()
{
    if (vec.empty()) {
        return EmptyContainer;
    }
    auto v = vec.back();
    return v;
}

bool StdLibStack::isEmpty()
{
    return vec.empty();
}

void StdLibStack::clear()
{
    if (false == vec.empty()) {
        vec.clear();
    }
}
