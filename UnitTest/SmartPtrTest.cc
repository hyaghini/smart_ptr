/*
 * tempTest.cc
 *
 *  Created on: Mar 11, 2019
 *      Author: hyaghini
 */
#include <gtest/gtest.h>
#include "../SmartPtrTemplate.h"


TEST(SmartPtr, SharedPtr)
{
    new_ptr::shared_ptr<int> p1;
    p1 = new_ptr::make_shared<int> (5);
    new_ptr::shared_ptr<int> p2 = p1;

    ASSERT_EQ(*p1, *p2);

    *p1 = 7;
    ASSERT_EQ(*p1, 7);
}

TEST(SmartPtr, CheckRawPtr)
{
    int *p1 = new int(4);
    new_ptr::shared_ptr<int> ptr(p1);
    ASSERT_EQ(*ptr, 4);

//    delete p1;
//    ASSERT_EQ(*ptr, 4);
}

TEST(SmartPtr, CheckScopes)
{
    new_ptr::shared_ptr<int> p1 = new_ptr::make_shared<int>(9);
    {
        new_ptr::shared_ptr<int> p2 = p1;
        ASSERT_EQ(*p2, *p1);
    }

    ASSERT_EQ(9, *p1);

}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
