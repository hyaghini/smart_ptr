/*!
 * **************************************************
 * @file SmartPtrTemplate.h
 * @brief This class implements a smart pointer
 *
 * shared_ptr class allocates memory and returns a shared
 * pointer for that. Memory management including the sharing
 * and deleting the memory is handled inside the class.
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

#ifndef SMART_PTR_TEMPLATE
#define SMART_PTR_TEMPLATE

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
class shared_ptr{
    T *p;
    int *count;

public:
    /*!
     * @brief Default constructor for shared_ptr
     *
     * @return An instance of shared_ptr
     */
    shared_ptr();

    /*!
     * @brief Specialized Constructor for shared_ptr
     *
     * @param inputPtr : Address of the memory that will be shared
     * @return An instance of the shared_ptr
     */
    shared_ptr(T *inputPtr);

    /*!
     * @brief Destructor for shared_ptr
     *
     * The number of shared pointers will be decreased by 1 and
     * memory will be freed if all the pointers are destructed
     */
    ~shared_ptr();

    /*!
     * @brief Overloaded * operator to return a reference to the shared memory
     */
    T & operator*();

    /*!
     * @brief Overloading the assignment operator '='
     *
     * @param input : The pointer from which we are copying
     * @return A copied shared_ptr
     */
    shared_ptr& operator=(const shared_ptr &input);

    /*!
     * @brief Copy Constructor for shared_ptr
     *
     * @param inputPtr : Reference to a pointer whose data will be used in the new shared pointer
     * @return An instance of shared_ptr
     */
    shared_ptr(const shared_ptr &inputPtr);
};

/*!
 * @brief This function allocates memory to be used in the shared_ptr instance
 *
 * @param T : Type of the pointer
 * @param Args : Value of the memory where pointer points to
 * @return An instance of the shared_ptr
 */
template<class T, class ... Args>
shared_ptr<T> make_shared(Args &&... args);

}


#endif
