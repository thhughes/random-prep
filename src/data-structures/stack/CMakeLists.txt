

# Add the include directory for this module
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB stack-cpp CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB stack-h CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp")

add_library(stack "")
target_sources( stack
  PRIVATE ${stack-cpp}
  PUBLIC ${stack-h}
)
target_link_libraries(stack PUBLIC data-structures-shared)

add_subdirectory(test)
