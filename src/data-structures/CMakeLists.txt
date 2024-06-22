
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(data-structures-shared data-structures-shared.cpp)

## 
## Shared Library for all of the subdir content 
## 
add_library(data-structures-global-shared STATIC 
    data-structures-shared.cpp)

##
## Add all subdirectories with intent to create the libraries 
##
add_subdirectory(queue)
add_subdirectory(stack)

##
## Build Interface Library 
##
add_library(data-structures INTERFACE)
target_link_libraries(data-structures INTERFACE 
    data-structures-global-shared
    queue
    stack
    )















# include_directories(${CMAKE_CURRENT_LIST_DIR}/include )

# add_subdirectory(queue)


# add_library(queue SHARED
#     file1.cpp
#     file2.cpp
# )

# add_library(library2 SHARED
#     file3.cpp
#     file4.cpp
# )

# add_library(data-structures INTERFACE)

# # Link the master library with the other libraries
# target_link_libraries(data-structures INTERFACE
#     library1
#     library2
# )



# add_library(src-lib "")

# file(GLOB src-lib-cpp CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
# file(GLOB src-lib-h CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp")


# target_sources(src-lib
#   PRIVATE ${src-lib-cpp}
#   PUBLIC ${src-lib-h}
#   )

# target_include_directories(src-lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include )
# add_subdirectory(test)