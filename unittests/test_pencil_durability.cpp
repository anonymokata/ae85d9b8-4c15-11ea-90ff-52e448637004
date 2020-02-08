#include "../Paper.h"
#include "../Pencil.h"
#include "gtest/gtest.h"

class PencilDurability : public ::testing::Test
{
protected:
    void SetUp() override { pencil = Pencil(15); }

    Pencil pencil;
    Paper paper;
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

TEST_F(PencilDurability, DullPencilCanWriteSpaceCharacters)
{
    pencil = Pencil(0);
    const std::string word = " \n\r\t";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), word);
}

TEST_F(PencilDurability, DullPencilCannotWriteNonSpaceCharacters)
{
    pencil = Pencil(0);
    const std::string word = "word with\nspaces";
    const std::string expected_output = "         \n      ";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

TEST_F(PencilDurability, PencilDullsWithUse)
{
    pencil = Pencil(3);
    const std::string word = "word";
    const std::string expected_output = "wor ";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

TEST_F(PencilDurability, UppercaseLettersErodeByTwo)
{
    pencil = Pencil(4);
    const std::string word = "Word";
    const std::string expected_output = "Wor ";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

TEST_F(PencilDurability, ErodePencilPastZero)
{
    pencil = Pencil(3);
    const std::string word = "ABc";
    // TODO: Clarify expected behavior with stakeholder
    // if writing uppercase letter with insufficient durability
    const std::string expected_output = "AB ";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

TEST_F(PencilDurability, SpaceCharactersDoNotErodePencil)
{
    pencil = Pencil(3);
    const std::string word = "a b\nc";
    const std::string expected_output = "a b\nc";

    pencil.write(paper, word);

    ASSERT_EQ(paper.get_text(), expected_output);
}

// TODO: Clarify expected handling of numbers and symbols
TEST_F(PencilDurability, PencilCannotWriteNumbers)
{
    pencil = Pencil(3);
    const std::string word = "2";

    EXPECT_ANY_THROW(pencil.write(paper, word));
}

TEST_F(PencilDurability, CanSharpenDullPencil)
{
    pencil = Pencil(3);
    const std::string word = "abc";
    pencil.write(paper, word);

    pencil.sharpen();

    pencil.write(paper, word);
    ASSERT_EQ(paper.get_text(), word + word);
}
