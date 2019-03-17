cmake_minimum_required(VERSION 3.0)

project(basic_test)

################################
# GTest
################################
ADD_SUBDIRECTORY (../../googletest-release-1.8.1 /home/hyaghini/Documents/git_projects/googletest-release-1.8.1/build EXCLUDE_FROM_ALL)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
add_executable( runUnitTests SmartPtrTest.cc )
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main)
add_test( runUnitTests runUnitTests )

