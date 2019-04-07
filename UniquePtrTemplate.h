/*!
 * **************************************************
 * @file UniquePtrTemplate.h
 * @brief This class implements a unique pointer
 *
 * unique_ptr class allocates memory and returns a unique smart
 * pointer for that. Memory management such as deleting the
 * memory is handled inside the class.
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
 * @date 03/26/2019
 *
 * ****************************************************
 */

#ifndef UNIQUE_PTR_TEMPLATE
#define UNIQUE_PTR_TEMPLATE

#include <iostream>
#include <memory>

/*!
 *  @namespace new_ptr namespace is to distinguish
 *  the custom implemnted shared_ptr from the std's
 */

namespace new_ptr{

/*!
 * @class unique_ptr
 *
 * @brief Template implementation of a smart unique pointer.
 */
template<typename T>
class unique_ptr{
    T *p;        ///< Pointer to the unique memory

public:
    /*!
     * @brief Default constructor for unique_ptr
     *
     * @return An instance of unique_ptr
     */
    unique_ptr();

    /*!
     * @brief Specialized Constructor for unique_ptr
     *
     * @param inputPtr : Address of the memory that will be pointed to
     * @return An instance of the unique_ptr
     */
    unique_ptr(T *inputPtr);

    /*!
     * @brief Destructor for unique_ptr
     *
     * Memory will be freed if the pointer is destructed
     */
    ~unique_ptr();

    /*!
     * @brief Copy Constructor for unique_ptr
     *
     * @param inputPtr : An R-Value reference to a pointer whose data will
     *  be used in the new unique pointer
     *
     * @return An instance of unique_ptr
     */
    unique_ptr(unique_ptr&& inputPtr);

    /*!
     * @brief Copy Constructor for unique_ptr
     *
     * @param inputPtr : An L-Value reference to a pointer whose data will
     *  be used in the new unique pointer
     *
     * @return An instance of unique_ptr
     */
    unique_ptr(unique_ptr& inputPtr);

    /*!
     * @brief Overloaded * operator to return a reference to the pointed memory
     *
     * @return T& : Reference to the unique memory
     */
    T & operator*();

    /*!
     * @brief Overloading the assignment operator '='
     *
     * @param input : The R-Value pointer from which we are copying
     *
     * @return unique_ptr& : A copied unique_ptr
     */
    unique_ptr& operator=(unique_ptr&& input);

    /*!
     * @brief Overloading the assignment operator '='
     *
     * @param input : The L-Value pointer from which we are copying
     *
     * @return unique_ptr& : A copied unique_ptr
     */
    unique_ptr& operator=(unique_ptr& input);

    /*!
     * @brief Returns the address of the memory that is being pointed to
     *
     * @return T* : pointer to memory
     */
    T* get();

    /*!
     * @brief Releases ownership of its stored pointer, by returning its value and
     * replacing it with a null pointer.
     *
     * @return T* : A pointer to the object managed by unique_ptr before the call.
     */
    T* release();

    /*!
     * Destroys the object currently managed by the unique_ptr (if any) and takes ownership of new_ptr.
     *
     * @param new_ptr : Pointer whose ownership is taken over by the object.
     */
    void reset(T* new_ptr);
};

/*!
 * Constructs an object of type T and wraps it in a unique_ptr.
 *
 * @param arg : list of arguments with which an instance of T will be constructed.
 *
 * @return unique_ptr<T> : unique_ptr of an instance of type T.
 */
template<typename T>
unique_ptr<T> make_unique(const T& arg);

}

#include "UniquePtrTemplate.def.h"

#endif
