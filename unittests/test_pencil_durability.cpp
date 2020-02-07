#include "../Paper.h"
#include "../Pencil.h"
#include "gtest/gtest.h"

class PencilDurability : public ::testing::Test {
protected:
    void SetUp() override
    {
    }

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
    const std::string second_word = "_second";
    const std::string expected_result = "first_second";

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

