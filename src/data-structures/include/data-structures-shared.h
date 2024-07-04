//
//  data-structures-shared.h
//  dsr
//

#pragma once 
namespace DataStructures {


/// @brief Could do a more generic container, but trying to keep this simple.
/// These structures are intended to focus on how they work/building to the interface/etc.
/// Future work: 
///     - Learn more about templates to allow for full blown generic typing 
///     - Learn more about how standard lib handles the allocator object and empty 
///
///
struct GenericContainer  {
    int obj;
    bool empty = false;
};
using Typ = GenericContainer;

extern const Typ EmptyContainer;

}
