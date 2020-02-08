#include "Paper.h"

#include <cassert>

const std::string& Paper::get_text() const
{
    return mText;
}

void Paper::write(const std::string& text)
{
    mText += text;
}

void Paper::replace_text(size_t from, const std::string& replacement)
{
    assert(mText.size() - from >= replacement.size());
    mText.replace(from, replacement.size(), replacement);
}
