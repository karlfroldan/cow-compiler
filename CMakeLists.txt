cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)
project(CVM) # Cow Virtual Machine
add_executable(CVM src/main.cpp src/keywords.cpp src/virtualmachine.cpp)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(
    cvm_test
    test/test_main.cpp
    src/virtualmachine.cpp  
    src/keywords.cpp
)

target_link_libraries(cvm_test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main) 
include(GoogleTest)
gtest_discover_tests(cvm_test)