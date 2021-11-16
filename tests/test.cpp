#include <gtest/gtest.h>
#include "walk.h"
#include "stat.h"

// Demonstrate some basic assertions.
TEST(defTest, BasicAssertions)
{
    auto next  = step(2, 2.);
    EXPECT_LE(next, 4.);
}

TEST(defTestWalk, BasicAssertions)
{
    auto next = step(2, 2.);
    EXPECT_LE(next, 4.);

    runWalk();
}

TEST(defTestArrival, BasicAssertions)
{
    getArrival();
}