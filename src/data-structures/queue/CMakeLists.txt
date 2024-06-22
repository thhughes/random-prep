
# Add the include directory for this module
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB queue-cpp CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB queue-h CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp")

add_library(queue "")
target_sources( queue
  PRIVATE ${queue-cpp}
  PUBLIC ${queue-h}
)
target_link_libraries(queue PUBLIC data-structures-shared)

add_subdirectory(test)