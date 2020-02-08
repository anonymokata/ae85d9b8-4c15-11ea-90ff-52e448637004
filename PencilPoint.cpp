#include "PencilPoint.h"

#include <stdexcept>
namespace
{
size_t calculate_new_durability(char character, size_t old_durability)
{
    size_t new_durability = old_durability;
    if (isupper(character))
        new_durability -= 2;
    else if (islower(character))
        new_durability -= 1;
    else if (isspace(character))
        new_durability -= 0;  // Do nothing
    else
        throw std::runtime_error("Unable to writer character: " +
                                 std::string(1, character));

    if (new_durability == static_cast<size_t>(-1)) new_durability = 0;
    return new_durability;
}

char calculate_character_to_write(char character, size_t durability)
{
    if (durability > 0 || isspace(character))
        return character;
    else
        return ' ';
}
}

PencilPoint::PencilPoint(size_t durability, size_t length)
    : mDurability(durability)
    , mInitialDurability(durability)
    , mLength(length)
{
}

char PencilPoint::write(char character)
{
    const char result = calculate_character_to_write(character, mDurability);
    mDurability = calculate_new_durability(character, mDurability);
    return result;
}

std::string PencilPoint::write(const std::string& to_write)
{
    std::string written_text;
    for (char c : to_write)
        written_text += write(c);
    return written_text;
}

void PencilPoint::sharpen()
{
    if (mLength > 0)
    {
        mLength--;
        mDurability = mInitialDurability;
    }
}
