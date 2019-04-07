# Smart Pointer Implementation  

## Introduction
 This is a basic implementation of smart pointers which is available in C++ Standard Library. Two smart pointers including

shared_ptr and unique_ptr were implemented under the new_ptr namespace. 

## Configuring CodeCoverage
Inside the UnitTest build directory

* cmake -DCMAKE_BUILD_TYPE=Debug ..
* make
* make TestUniquePtr_coverage
* make TestSharedPtr_coverage 

* By making these files the corresponding code coverage folder will be created. 

* Open the report with index.html file in the generated code coverage folders in the build folder.

## How To Use

### 1: Using shared pointer
 * For information regarding shared pointer: [Click Here](shared_ptr_README.md)

 where Type is type of the variable that pointer points to

### 2: Using unique pointer
 * For information regarding unique pointer: [Click Here](unique_ptr_README.md)

