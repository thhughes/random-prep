//
//  data-structures-shared.h
//  dsr
//

#pragma once 
namespace DataStructures {


/// @brief Could do a more generic container, but trying to keep this simple.
/// These strucutres are intended to focus on how they work/building to the interface/etc.
/// If we were to get more complicated, the limitations would not end at the container, we'd also
/// need to determine an ownership model between the structures and the objects. At this 2 seconds
/// deciding those questions isn't really something that I want to do - likely a future consideration though.
struct GenericContainer  {
    int obj;
    bool empty = false;
};
using Typ = GenericContainer;

extern const Typ EmptyContainer;

}
