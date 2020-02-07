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