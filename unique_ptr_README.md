# Unique Pointer Implementation  

## Introduction
 This document is a summary for the class shared_ptr under 

the new_ptr namespace. This class is a custom implementation

of the shared pointer which is available in C++ Standard Library.


## How To Use

### 1: Declaring a shared pointer ptr
 * new_ptr::shared_ptr<Type> ptr;

 where Type is type of the variable that pointer points to

### 2: Allocating memory and assigning a value to the pointer
 * ptr = new_ptr::make_shared<Type>(Val)

where Type is type of the pointer and Val is its value

