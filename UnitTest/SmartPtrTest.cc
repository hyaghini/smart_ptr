/*
 * tempTest.cc
 *
 *  Created on: Mar 11, 2019
 *      Author: hyaghini
 */
#include <gtest/gtest.h>
#include "../SmartPtrTemplate.h"


class shared_ptrTest : public ::testing::Test {
protected:
    new_ptr::shared_ptr<int> ptr0_;
    new_ptr::shared_ptr<int> ptr1_;
    void SetUp() override {
        ptr0_ = new_ptr::make_shared<int>(1);
        ptr1_ = new_ptr::make_shared<int>(4);
    }

    new_ptr::shared_ptr<int> ptr2_ = new_ptr::make_shared<int>(10);
};


TEST_F(shared_ptrTest, Check_Assigning_And_Reading)
{
    ASSERT_EQ(*ptr0_, 1);

    *ptr0_ = 7;
    ASSERT_EQ(*ptr0_, 7);
}

TEST_F(shared_ptrTest, Check_AssignmentOperator)
{
    EXPECT_NE(*ptr0_, *ptr1_);
    ptr0_ = ptr1_;
    ASSERT_EQ(*ptr0_, *ptr1_);

    ASSERT_EQ(ptr1_.use_count(), 2);
//    EXPECT_EQ(ptr0_.getNumberOfPointers(), 0);
}


TEST_F(shared_ptrTest, Check_HandlingNumOfPtrs)
{


    ASSERT_EQ(ptr2_.use_count(), 1);

    {
        new_ptr::shared_ptr<int> ptr2 = ptr2_;
        new_ptr::shared_ptr<int> ptr3;
        ptr3 = ptr2_;
        ASSERT_EQ(ptr2_.use_count(), 3);
    }
    ASSERT_EQ(ptr2_.use_count(), 1);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
