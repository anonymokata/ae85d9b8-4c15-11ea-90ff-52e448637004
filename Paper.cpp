#include "Paper.h"

#include <cassert>

namespace
{
char edited_char(char original, char replacement)
{
    if (isspace(original))
        return replacement;
    else
        return '@';
}
}

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

void Paper::edit(size_t position, const std::string& new_text)
{
    for (size_t edit_index = 0; edit_index < new_text.size(); ++edit_index)
    {
        const size_t paper_index = edit_index + position;
        if (paper_index > mText.size())
            break;
        const char original_character = mText[paper_index];
        const char new_character = new_text[edit_index];
        mText[paper_index] = edited_char(original_character, new_character);
    }
}
