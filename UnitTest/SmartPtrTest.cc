/*
 * tempTest.cc
 *
 *  Created on: Mar 11, 2019
 *      Author: hyaghini
 */
#include <gtest/gtest.h>
#include "../SmartPtrTemplate.h"


TEST(SharedPointer_HandlingNumberOfPointers, Check_Constructors_Destructor_AssignOperator)
{
    using namespace new_ptr;
    shared_ptr<int> ptr1 = make_shared<int>(10);

    ASSERT_EQ(ptr1.getNumberOfPointers(), 1);

    {
        shared_ptr<int> ptr2 = ptr1;
        shared_ptr<int> ptr3;
        ptr3 = ptr1;
        ASSERT_EQ(ptr1.getNumberOfPointers(), 3);
    }
    ASSERT_EQ(ptr1.getNumberOfPointers(), 1);
}


TEST(SharedPointer, Check_Assigning_Reading_Values)
{
    new_ptr::shared_ptr<int> p1;
    p1 = new_ptr::make_shared<int> (5);
    new_ptr::shared_ptr<int> p2 = p1;

    ASSERT_EQ(*p1, *p2);

    *p1 = 7;
    ASSERT_EQ(*p1, 7);
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
