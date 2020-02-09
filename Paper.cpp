#include "Paper.h"

#include <cassert>
#include <sstream>
#include <stdexcept>

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

void Paper::verify_request_bounds(size_t position, const std::string& text)
{
    if (position + text.size() > mText.size())
    {
        std::ostringstream msg;
        msg << "Out of range: Cannot write text <" << text << "> at position <"
            << position << ">";
        msg << "(Current text length: <" << mText.size() << "\n";
        throw std::out_of_range(msg.str());
    }
}

void Paper::replace_text(size_t from, const std::string& replacement)
{
    verify_request_bounds(from, replacement);
    mText.replace(from, replacement.size(), replacement);
}

void Paper::edit(size_t position, const std::string& new_text)
{
    verify_request_bounds(position);
    for (size_t edit_index = 0; edit_index < new_text.size(); ++edit_index)
    {
        const size_t paper_index = edit_index + position;
        if (paper_index > mText.size()) break;
        const char original_character = mText[paper_index];
        const char new_character = new_text[edit_index];
        mText[paper_index] = edited_char(original_character, new_character);
    }
}
