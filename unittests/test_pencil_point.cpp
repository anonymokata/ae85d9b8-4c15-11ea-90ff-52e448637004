#include "../PencilPoint.h"
#include "gtest/gtest.h"

void test_write_word_with_point(size_t durability,
                                const std::string& to_write,
                                const std::string& expected_output)
{
    const std::string actual_output = PencilPoint(durability).write(to_write);
    ASSERT_EQ(actual_output, expected_output);
}

TEST(PencilPoint, DullPointCanWriteSpaceCharacters)
{
    test_write_word_with_point(0, " \n\r\t", " \n\r\t");
}

// TODO: Clarify expected handling of numbers and symbols
TEST(PencilPoint, PencilCannotWriteNumbers)
{
    EXPECT_ANY_THROW(PencilPoint().write("2"));
}

TEST(PencilPoint, DullPencilCannotWriteNonSpaceCharacters)
{
    test_write_word_with_point(0, "word with\nspaces", "         \n      ");
}

TEST(PencilPoint, PencilDullsWithUse)
{
    test_write_word_with_point(3, "word", "wor ");
}

TEST(PencilPoint, UppercaseLettersErodeByTwo)
{
    test_write_word_with_point(4, "Word", "Wor ");
}

TEST(PencilPoint, ErodePencilPastZero)
{
    // TODO: Clarify expected behavior with stakeholder
    test_write_word_with_point(3, "ABc", "AB ");
}

TEST(PencilPoint, SpaceCharactersDoNotErodePencil)
{
    test_write_word_with_point(3, "a b\nc", "a b\nc");
}

TEST(PencilPoint, CanSharpenDullPencil)
{
    PencilPoint point(3);
    const std::string word = "abc";
    point.write(word);

    point.sharpen();

    const std::string expected_result = "abc";
    const std::string actual_result = point.write(word);
    ASSERT_EQ(actual_result, expected_result);
}

TEST(PencilPoint, CannotSharpenPencilPastInitialLength)
{
    const size_t initial_length = 2;
    PencilPoint point(3, initial_length);

    // Sharpen pencil to length 0
    for (size_t i = 0; i < initial_length; ++i)
        point.sharpen();

    // Dull the pencil
    const std::string word = "abc";
    point.write(word);

    point.sharpen();

    const std::string expected_output = "   ";
    const std::string actual_output = point.write(word);

    ASSERT_EQ(actual_output, expected_output);
}
