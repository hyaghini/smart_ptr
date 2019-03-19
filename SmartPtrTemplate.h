/*
 * tempTest.cc
 *
 *  Created on: Mar 11, 2019
 *      Author: hyaghini
 */
#include <iostream>
#include <memory>

/*
 *
 *  \namespace new_ptr namespace is to distinguish
 *  the costum implemnted shared_ptr from the std's
 *
 */

namespace new_ptr{

/** \brief
 *
 * template implementation of a
 * smart pointer.
 *
 * Usage: new_ptr::shared_ptr<Type> p;
 *        p = new_ptr::make_shared<Type> (Value);
 *
 *
 */
template<typename T>
class shared_ptr{
    T *p;
    int *count;

public:
    shared_ptr(){
        count = new int;
        *count = 1;
    }

    shared_ptr(T *po) : p(po){
        count = new int;
        *count = 1;

        std::cout << "new p is created" << std::endl;
    }
    ~shared_ptr()
    {
        (*count)--;
        if(*count == 0)
        {
            delete p;
            std::cout << "p is deleted: " << *count << std::endl;
            delete count;
        }

    }

    T & operator*()
    {
        return *p;
    }

    /**
     *
     * Overloading the assign operator =
     *
     */
    shared_ptr& operator=(const shared_ptr &input)
    {
        std::cout << "called the = operator" << std::endl;
        this->p = input.p;
        (*input.count)++;
        std::cout << "count is = " << *input.count << std::endl;
        this->count = input.count;
        return *this;
    }

    /**
     *
     * Copy Constructor
     *
     *
     */
    shared_ptr(const shared_ptr &ptr)
    {
        std::cout << "called the copy constructor" << std::endl;

        this->p = ptr.p;
        (*(ptr.count))++;
        this->count = ptr.count;
        std::cout << "p is deleted: " << *ptr.count << std::endl;
    }
};

template<class T, class ... Args>
shared_ptr<T> make_shared(Args &&... args)
{
    T* tmp = new T(args...);
    shared_ptr<T> ptr (tmp);
    return ptr;
}

}



