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
shared_ptr<T>::shared_ptr(){
    count = new int;
    *count = 1;
}

template<typename T>
shared_ptr<T>::shared_ptr(T *po) : p(po){
    count = new int;
    *count = 1;

    std::cout << "new p is created" << std::endl;
}

template<typename T>
shared_ptr<T>::~shared_ptr()
{
    (*count)--;
    std::cout << "inside destructor; count = " << *count << std::endl;
    if(*count == 0)
    {
        delete p;
        std::cout << "p is deleted: " << *count << std::endl;
        delete count;
    }
}

template<typename T>
shared_ptr<T>::shared_ptr(const shared_ptr &ptr)
{
    std::cout << "called the copy constructor" << std::endl;

    this->p = ptr.p;
    (*(ptr.count))++;
    this->count = ptr.count;
    std::cout << "p is deleted: " << *ptr.count << std::endl;
}

template<typename T>
T & shared_ptr<T>::operator*()
{
    return *p;
}

template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr &input)
{
    std::cout << "called the = operator" << std::endl;
    this->p = input.p;
    (*input.count)++;
    std::cout << "count is = " << *input.count << std::endl;
    this->count = input.count;
    return *this;
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

