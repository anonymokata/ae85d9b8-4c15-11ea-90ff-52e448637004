#include "Paper.h"

const std::string& Paper::get_text() const
{
    return mText;
}

void Paper::write(const std::string& text)
{
    mText += text;
}

void Paper::erase_range(size_t from, size_t to)
{
    for (size_t i = from; i < to; ++i)
        mText[i] = ' ';
}
