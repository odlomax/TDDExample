cmake_minimum_required(VERSION 3.5)

project(TestDrivenDevelopment LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(src test.cpp stack.h)

add_executable(TestDrivenDevelopment ${src})

find_package(Boost REQUIRED)
target_link_libraries(TestDrivenDevelopment Boost::boost)

find_package(Boost COMPONENTS unit_test_framework)
if (Boost_unit_test_framework_FOUND)
    # Test compilation is much faster if compiled library is found.
    target_link_libraries(TestDrivenDevelopment Boost::unit_test_framework)
    target_compile_definitions(TestDrivenDevelopment PUBLIC BOOST_TEST_DYN_LINK)
endif()

include(CTest)

add_test(NAME test_suite
         COMMAND TestDrivenDevelopment -l test_suite)
