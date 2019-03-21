/*!
 * **************************************************
 * @file SmartPtrTemplate.cc
 * @brief Implementation of class members of the shared pointer.
 *
 * This file implements the shared_ptr constructors, destructor
 * and overloading operators.The class member functions keep track
 * of number of pointers to an address of memory using a counter.
 * When the counter is 0 the memory is freed in the class destructor.
 *
 * @sa SmartPtrTemplate.h
 *
 * @section  LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 *
 * @author Hamed Yaghini (hamed84.yaghini@gmail.com)
 * @date 03/20/2019
 *
 * ****************************************************
 */


#include <iostream>
#include <memory>
#include "SmartPtrTemplate.h"


namespace new_ptr{

template<typename T>
shared_ptr<T>::shared_ptr()
{

}

template<typename T>
shared_ptr<T>::shared_ptr(T *po) : p(po){
    count = new int;
    *count = 1;

    std::cout << "New pointer is created; Number of shared pointers = 1" << std::endl;
}

template<typename T>
shared_ptr<T>::~shared_ptr()
{
    (*count)--;
    std::cout << "A shared pointer is destructed; Number of shared pointers = " << *count << std::endl;
    if(*count == 0)
    {
        delete p;
        std::cout << "The shared pointer memory is freed" << std::endl;
        delete count;
    }
}

template<typename T>
shared_ptr<T>::shared_ptr(const shared_ptr &ptr)
{
    this->p = ptr.p;
    (*(ptr.count))++;
    this->count = ptr.count;
    std::cout << "Copy constructor is called; Number of shared pointers = " << *(ptr.count) << std::endl;
}

template<typename T>
T & shared_ptr<T>::operator*()
{
    return *p;
}

template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr &input)
{
    this->p = input.p;
    (*input.count)++;
    this->count = input.count;

    std::cout << "Assignment operator is called; Number of shared pointers = " << *(input.count) << std::endl;

    return *this;
}

template<typename T>
int shared_ptr<T>::getNumberOfPointers()
{
    return *count;
}

template<class T, class ... Args>
shared_ptr<T> make_shared(Args &&... args)
{
    T* tmp = new T(args...);
    shared_ptr<T> ptr (tmp);
    return ptr;
}

template class shared_ptr<double>;
template class shared_ptr<int>;
template shared_ptr<int> make_shared<int>(int&&);
template shared_ptr<double> make_shared<double>(double&&);

}

