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
 * @class shared_ptr
 *
 * @brief Template implementation of a smart pointer.
 */
template<typename T>
class unique_ptr{
    T *p;        ///< Pointer to the unique memory

public:
    /*!
     * @brief Default constructor for shared_ptr
     *
     * @return An instance of shared_ptr
     */
    unique_ptr();

    /*!
     * @brief Specialized Constructor for shared_ptr
     *
     * @param inputPtr : Address of the memory that will be shared
     * @return An instance of the shared_ptr
     */
    unique_ptr(T *inputPtr);

    /*!
     * @brief Destructor for shared_ptr
     *
     * The number of shared pointers will be decreased by 1 and
     * memory will be freed if all the pointers are destructed
     */
    ~unique_ptr();

    /*!
     * @brief Copy Constructor for shared_ptr
     *
     * @param inputPtr : Reference to a pointer whose data will be used in the new shared pointer
     * @return An instance of shared_ptr
     */
    unique_ptr(unique_ptr&& inputPtr);

    unique_ptr(unique_ptr& inputPtr);

    /*!
     * @brief Overloaded * operator to return a reference to the shared memory
     *
     * @return T& : Reference to the shared memory
     */
    T & operator*();

    /*!
     * @brief Overloading the assignment operator '='
     *
     * @param input : The pointer from which we are copying
     * @return shared_ptr& : A copied shared_ptr
     */
    unique_ptr& operator=(unique_ptr&& input);
    unique_ptr& operator=(unique_ptr& input);

    T* get();

};

template<typename T>
unique_ptr<T> make_unique(const T& arg);

}

#include "UniquePtrTemplate.def.h"

#endif
