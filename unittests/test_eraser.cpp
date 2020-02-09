#include "../Eraser.h"
#include "gtest/gtest.h"

TEST(Eraser, EraseEntireWord)
{
    Eraser eraser;
    const auto result = eraser.erase("word");
    ASSERT_EQ(result, "    ");
}

TEST(Eraser, EraserDegrades)
{
    Eraser eraser(2);
    const auto result = eraser.erase("word");
    ASSERT_EQ(result, "wo  ");
}

TEST(Eraser, WhitespaceDoesNotDegradeEraser)
{
    Eraser eraser(2);
    const auto result = eraser.erase("w  d");
    ASSERT_EQ(result, "    ");
}