#include "../Paper.h"
#include "../Pencil.h"
#include "gtest/gtest.h"

TEST(PencilDurability, WriteEmptyStringToPaper)
{
    Pencil pencil;
    Paper paper;

    pencil.write(paper, "");

    ASSERT_EQ(paper.get_text(), "");
}

TEST(PencilDurability, WriteNonemptyString)
{
    Pencil pencil;
    Paper paper;

    const std::string test_string = "word";
    pencil.write(paper, test_string);

    ASSERT_EQ(paper.get_text(), test_string);
}