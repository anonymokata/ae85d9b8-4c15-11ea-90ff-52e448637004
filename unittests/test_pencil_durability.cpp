#include "../Eraser.h"
#include "../Paper.h"
#include "../Pencil.h"
#include "../PencilPoint.h"
#include "gtest/gtest.h"

class PencilDurability : public ::testing::Test
{
protected:
    Paper paper;
    Pencil pencil;
};

TEST_F(PencilDurability, WriteEmptyStringToPaper)
{
    pencil.write(paper, "");

    ASSERT_EQ(paper.get_text(), "");
}

TEST_F(PencilDurability, WriteNonemptyString)
{
    const std::string test_string = "word";
    pencil.write(paper, test_string);

    ASSERT_EQ(paper.get_text(), test_string);
}

TEST_F(PencilDurability, AppendStringToPaper)
{
    const std::string first_word = "first";
    const std::string second_word = " second";
    const std::string expected_result = "first second";

    pencil.write(paper, first_word);
    pencil.write(paper, second_word);

    ASSERT_EQ(paper.get_text(), expected_result);
}

TEST_F(PencilDurability, EraseWordFromPaper)
{
    pencil.write(paper, "onetwothree");
    pencil.erase(paper, "two");

    ASSERT_EQ(paper.get_text(), "one   three");
}

TEST_F(PencilDurability, EraseMultipleWordsFromPaper)
{
    pencil.write(paper, "onetwoone");
    pencil.erase(paper, "one");
    pencil.erase(paper, "one");

    ASSERT_EQ(paper.get_text(), "   two   ");
}

TEST_F(PencilDurability, EraseWordNotOnPaper)
{
    pencil.write(paper, "onetwoone");
    pencil.erase(paper, "three");

    ASSERT_EQ(paper.get_text(), "onetwoone");
}

TEST_F(PencilDurability, EditEmptyText)
{
    pencil.write(paper, "abc   ghi");
    pencil.edit(paper, 3, "def");

    ASSERT_EQ(paper.get_text(), "abcdefghi");
}

TEST_F(PencilDurability, OverwritePreviousText)
{
    pencil.write(paper, "abcdefghi");
    pencil.edit(paper, 3, "def");

    ASSERT_EQ(paper.get_text(), "abc@@@ghi");
}

TEST_F(PencilDurability, EditOutOfBounds)
{
    paper.write("abc");
    pencil.edit(paper, 1, "def");
    ASSERT_EQ(paper.get_text(), "a@@");
}
