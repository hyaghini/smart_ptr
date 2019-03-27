/*!
 * **************************************************
 * @file UniquePtrTemplate.def.h
 * @brief Implementation of class members of the unique pointer.
 *
 * This file implements the shared_ptr constructors, destructor
 * and overloading operators.
 *
 * @sa UniquePtrTemplate.h
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
#include "SharedPtrTemplate.h"


namespace new_ptr{

template<typename T>
unique_ptr<T>::unique_ptr()
{
    p = nullptr;
}

template<typename T>
unique_ptr<T>::unique_ptr(T *po) : p(po){

}

template<typename T>
unique_ptr<T>::~unique_ptr()
{
    if(p != nullptr)
    {
        delete p;
    }
}

template<typename T>
unique_ptr<T>::unique_ptr(unique_ptr&& ptr)
{
    this->p = ptr.p;
//    const_cast<unique_ptr&> (ptr).p = nullptr;
    ptr.p = nullptr;
}

template<typename T>
unique_ptr<T>::unique_ptr(unique_ptr& ptr)
{
    this->p = ptr.p;
//    const_cast<unique_ptr&> (ptr).p = nullptr;
    ptr.p = nullptr;
}

template<typename T>
T & unique_ptr<T>::operator*()
{
    return *p;
}

template<typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr&& input)
{
    this->p = input.p;
//    const_cast<unique_ptr&> (input).p = nullptr;
    input.p = nullptr;
    return *this;
}

template<typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr& input)
{
    this->p = input.p;
//    const_cast<unique_ptr&> (input).p = nullptr;
    input.p = nullptr;

    return *this;
}

template<typename T>
T* unique_ptr<T>::get()
{
    return p;
}

template<typename T>
unique_ptr<T> make_unique(const T& arg)
{
    T* tmp = new T(arg);
    unique_ptr<T> ptr(tmp);
    return ptr;
}

}

