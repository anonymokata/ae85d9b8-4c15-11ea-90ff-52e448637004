#include "Paper.h"

const std::string& Paper::get_text() const
{
    return mText;
}

void Paper::write(const std::string& text)
{
    mText = text;
}
