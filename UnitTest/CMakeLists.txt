cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

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
add_executable( TestSharedPtr SharedPtrTest.cc)
# Link test executable against gtest & gtest_main
target_link_libraries(TestSharedPtr gtest gtest_main)
add_test( TestSharedPtr runUnitTests )


add_executable( TestUniquePtr UniquePtrTest.cc)
# Link test executable against gtest & gtest_main
target_link_libraries(TestUniquePtr gtest gtest_main)
add_test( TestUniquePtr runUnitTests )


if(CMAKE_COMPILER_IS_GNUCXX)
LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules")
include(CodeCoverage)
APPEND_COVERAGE_COMPILER_FLAGS()
SETUP_TARGET_FOR_COVERAGE_LCOV(NAME TestUniquePtr_coverage
                              EXECUTABLE TestUniquePtr
                              DEPENDENCIES TestUniquePtr)

SETUP_TARGET_FOR_COVERAGE_LCOV(NAME TestSharedPtr_coverage
                              EXECUTABLE TestSharedPtr
                              DEPENDENCIES TestSharedPtr)
endif()
