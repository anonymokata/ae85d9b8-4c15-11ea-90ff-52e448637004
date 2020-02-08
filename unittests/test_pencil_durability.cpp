#include "../Eraser.h"
#include "../Paper.h"
#include "../Pencil.h"
#include "../PencilPoint.h"
#include "gtest/gtest.h"

class PencilDurability : public ::testing::Test
{
protected:
    Paper paper;
};

TEST_F(PencilDurability, WriteEmptyStringToPaper)
{
    Pencil pencil;
    pencil.write(paper, "");

    ASSERT_EQ(paper.get_text(), "");
}

TEST_F(PencilDurability, WriteNonemptyString)
{
    Pencil pencil;
    const std::string test_string = "word";
    pencil.write(paper, test_string);

    ASSERT_EQ(paper.get_text(), test_string);
}

TEST_F(PencilDurability, AppendStringToPaper)
{
    Pencil pencil(10, std::make_unique<PencilPoint>(15));
    const std::string first_word = "first";
    const std::string second_word = " second";
    const std::string expected_result = "first second";

    pencil.write(paper, first_word);
    pencil.write(paper, second_word);

    ASSERT_EQ(paper.get_text(), expected_result);
}

TEST_F(PencilDurability, CanSharpenDullPencil)
{
    Pencil pencil(10, std::make_unique<PencilPoint>(3));
    const std::string word = "abc";
    pencil.write(paper, word);

    pencil.sharpen();

    pencil.write(paper, word);
    ASSERT_EQ(paper.get_text(), word + word);
}

TEST_F(PencilDurability, CannotSharpenPencilPastInitialLength)
{
    const size_t initial_length = 2;
    Pencil pencil(initial_length, std::make_unique<PencilPoint>(3));
    for (size_t i = 0; i < initial_length; ++i)
        pencil.sharpen();

    const std::string word = "abc";
    pencil.write(paper, word);
    pencil.sharpen();
    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), "abc   ");
}

TEST_F(PencilDurability, EraseWordFromPaper)
{
    Pencil pencil(20, std::make_unique<PencilPoint>(15));
    pencil.write(paper, "onetwothree");
    pencil.erase(paper, "two");

    ASSERT_EQ(paper.get_text(), "one   three");
}

TEST_F(PencilDurability, EraseMultipleWordsFromPaper)
{
    Pencil pencil(
            20, std::make_unique<PencilPoint>(), std::make_unique<Eraser>(4));
    pencil.write(paper, "onetwoone");
    pencil.erase(paper, "one");
    pencil.erase(paper, "one");

    ASSERT_EQ(paper.get_text(), "on two   ");
}

TEST_F(PencilDurability, EraseWordNotOnPaper)
{
    Pencil pencil(
            20, std::make_unique<PencilPoint>(), std::make_unique<Eraser>(4));
    pencil.write(paper, "onetwoone");
    pencil.erase(paper, "three");

    ASSERT_EQ(paper.get_text(), "onetwoone");
}

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
