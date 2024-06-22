

# Add the include directory for this module
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB queue-cpp CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB queue-h CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp")

add_library(queue "")
target_sources( queue
  PRIVATE ${queue-cpp}
  PUBLIC ${queue-h}
)

add_subdirectory(test)







# target_sources(src-lib
#   PRIVATE ${src-lib-cpp}
#   PUBLIC ${src-lib-h}
#   )

# target_include_directories(src-lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include )
# add_subdirectory(test)


# add_library(src-lib "")

# file(GLOB src-lib-cpp CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
# file(GLOB src-lib-h CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp")


# target_sources(src-lib
#   PRIVATE ${src-lib-cpp}
#   PUBLIC ${src-lib-h}
#   )

# target_include_directories(src-lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include )
# add_subdirectory(test)