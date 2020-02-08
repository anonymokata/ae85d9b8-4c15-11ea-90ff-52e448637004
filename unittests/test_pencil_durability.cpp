#include "../Paper.h"
#include "../Pencil.h"
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
    Pencil pencil(15);
    const std::string first_word = "first";
    const std::string second_word = " second";
    const std::string expected_result = "first second";

    pencil.write(paper, first_word);
    pencil.write(paper, second_word);

    ASSERT_EQ(paper.get_text(), expected_result);
}

TEST_F(PencilDurability, DullPencilCanWriteSpaceCharacters)
{
    Pencil pencil(0);
    const std::string word = " \n\r\t";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), word);
}

TEST_F(PencilDurability, DullPencilCannotWriteNonSpaceCharacters)
{
    Pencil pencil(0);
    const std::string word = "word with\nspaces";
    const std::string expected_output = "         \n      ";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

TEST_F(PencilDurability, PencilDullsWithUse)
{
    Pencil pencil(3);
    const std::string word = "word";
    const std::string expected_output = "wor ";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

TEST_F(PencilDurability, UppercaseLettersErodeByTwo)
{
    Pencil pencil(4);
    const std::string word = "Word";
    const std::string expected_output = "Wor ";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

TEST_F(PencilDurability, ErodePencilPastZero)
{
    Pencil pencil(3);
    const std::string word = "ABc";
    // TODO: Clarify expected behavior with stakeholder
    // if writing uppercase letter with insufficient durability
    const std::string expected_output = "AB ";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

TEST_F(PencilDurability, SpaceCharactersDoNotErodePencil)
{
    Pencil pencil(3);
    const std::string word = "a b\nc";
    const std::string expected_output = "a b\nc";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

// TODO: Clarify expected handling of numbers and symbols
TEST_F(PencilDurability, PencilCannotWriteNumbers)
{
    Pencil pencil(3);
    const std::string word = "2";

    EXPECT_ANY_THROW(pencil.write(paper, word));
}

TEST_F(PencilDurability, CanSharpenDullPencil)
{
    Pencil pencil(3);
    const std::string word = "abc";
    pencil.write(paper, word);

    pencil.sharpen();

    pencil.write(paper, word);
    ASSERT_EQ(paper.get_text(), word + word);
}

TEST_F(PencilDurability, CannotSharpenPencilPastInitialLength)
{
    const size_t initial_length = 2;
    Pencil pencil(3, initial_length);
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
    Pencil pencil(20);
    pencil.write(paper, "onetwothree");
    pencil.erase(paper, "two");

    ASSERT_EQ(paper.get_text(), "one   three");
}

TEST_F(PencilDurability, EraseMultipleWordsFromPaper)
{
    Pencil pencil(20, 10, Eraser(4));
    pencil.write(paper, "onetwoone");
    pencil.erase(paper, "one");
    pencil.erase(paper, "one");

    ASSERT_EQ(paper.get_text(), "on two   ");
}

TEST_F(PencilDurability, EraseWordNotOnPaper)
{
    Pencil pencil(20, 10, Eraser(4));
    pencil.write(paper, "onetwoone");
    pencil.erase(paper, "three");

    ASSERT_EQ(paper.get_text(), "onetwoone");
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
