/*
 * tempTest.cc
 *
 *  Created on: Mar 11, 2019
 *      Author: hyaghini
 */
#include <iostream>
#include <memory>


namespace new_ptr{

/** \brief
 *
 * template implementation of a
 * smart pointer
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
        std::cout << *count << std::endl;

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


int main()
{
//    double *int1 = new double;
//    *int1 = 1;
//    new_ptr::shared_ptr<double> p1(int1);
//    {
//        new_ptr::shared_ptr<double> p2 = p1;
//        std::shared_ptr<int> p_std(new int);
//    std::shared_ptr<int> p1;
//    }
//    new_ptr::shared_ptr<int> p3(new int);
//    new_ptr::shared_ptr<int> p4(new int);

    new_ptr::shared_ptr<int> p1;
    p1 = new_ptr::make_shared<int> (4);
    std::cout << *p1 << std::endl;

    return 0;
}


