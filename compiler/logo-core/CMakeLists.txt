file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE TESTS "src/*.test.cpp")
list(REMOVE_ITEM SOURCES ${TESTS})

add_library(logo_core STATIC ${SOURCES})
set_target_properties(logo_core PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(logo_core PRIVATE src)
target_include_directories(logo_core PUBLIC include)
target_link_libraries(logo_core PUBLIC loco)

if(NOT ENABLE_TEST)
  return()
endif(NOT ENABLE_TEST)

nnas_find_package(GTest REQUIRED)

GTest_AddTest(logo_core_test ${TESTS})
target_include_directories(logo_core_test PRIVATE src)
target_link_libraries(logo_core_test logo_core)
