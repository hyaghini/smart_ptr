cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(SmartPtrTest)

################################
# GTest
################################
ADD_SUBDIRECTORY (../../googletest-release-1.8.1 ../../googletest-release-1.8.1/build EXCLUDE_FROM_ALL)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
add_executable( TestSmartPtr SmartPtrTest.cc)
# Link test executable against gtest & gtest_main
target_link_libraries(TestSmartPtr gtest gtest_main)
add_test( TestSmartPtr runUnitTests )

