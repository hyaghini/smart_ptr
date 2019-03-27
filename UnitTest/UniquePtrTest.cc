/*
 * tempTest.cc
 *
 *  Created on: Mar 11, 2019
 *      Author: hyaghini
 */
#include <gtest/gtest.h>
#include <iostream>
#include "../SharedPtrTemplate.h"
#include "../UniquePtrTemplate.h"


class unique_ptrTest : public ::testing::Test{
protected:
    new_ptr::unique_ptr<int> ptr_u0_;
    new_ptr::unique_ptr<int> ptr_u1_;
    void SetUp() override {
        ptr_u1_ = new_ptr::make_unique<int>(8);
    }
};


TEST_F(unique_ptrTest, Check_Constructors)
{
    ASSERT_EQ(ptr_u0_.get(), nullptr);
    new_ptr::unique_ptr<int> ptr_u2_(ptr_u1_);
    ASSERT_NE(ptr_u2_.get(), nullptr);
    ASSERT_EQ(ptr_u1_.get(), nullptr);
}

TEST_F(unique_ptrTest, Check_Assignment)
{
    ASSERT_NE(ptr_u1_.get(), nullptr);
    ptr_u0_ = ptr_u1_;
    ASSERT_EQ(ptr_u1_.get(), nullptr);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
