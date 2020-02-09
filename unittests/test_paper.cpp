#include "../Paper.h"
#include "gtest/gtest.h"

TEST(Paper, ReplaceOutOfBoundsIsError)
{
    Paper paper;
    ASSERT_ANY_THROW(paper.replace_text(1, "bad"));
}

TEST(Paper, ReplaceTextHalfOutOfBoundsThrowsError)
{
    Paper paper;
    paper.write("text");
    ASSERT_ANY_THROW(paper.replace_text(2, "text"));
}

TEST(Paper, EditPaperPastEndThrows)
{
    Paper paper;
    ASSERT_ANY_THROW(paper.edit(1, "text"));
}