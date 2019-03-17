/*
 * tempTest.cc
 *
 *  Created on: Mar 11, 2019
 *      Author: hyaghini
 */
#include <gtest/gtest.h>
#include "../sPtrWithPtrTemplate.h"


TEST(SmartPtr, SharedPtr)
{
    new_ptr::shared_ptr<int> p1(new int);
    *p1 = 3;
    new_ptr::shared_ptr<int> p2 = p1;
    ASSERT_EQ(*p1, *p2);
}




int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
