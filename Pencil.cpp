#include "Pencil.h"

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

Pencil::Pencil(size_t durability, size_t length, size_t eraser_durability)
    : mDurability(durability)
    , mInitialDurability(durability)
    , mLength(length)
    , mEraserDurability(eraser_durability)
{
}

void Pencil::write(Paper& paper, const std::string& new_text)
{
    std::string eroded_text;
    for (char c : new_text)
        eroded_text += write(c);
    paper.write(eroded_text);
}

void Pencil::erase(Paper& paper, const std::string& to_erase)
{
    const std::string& text = paper.get_text();
    auto erase_from = text.rfind(to_erase);
    const auto erase_to = erase_from + to_erase.size();

    if (to_erase.size() > mEraserDurability)
    {
        const auto characters_to_erase = to_erase.size() - mEraserDurability;
        erase_from += characters_to_erase;
        mEraserDurability = 0;
    }
    else
        mEraserDurability -= to_erase.size();
    paper.erase_range(erase_from, erase_to);
}

char Pencil::write(char character)
{
    const char result = calculate_character_to_write(character, mDurability);
    mDurability = calculate_new_durability(character, mDurability);
    return result;
}

void Pencil::sharpen()
{
    if (mLength > 0)
    {
        mLength--;
        mDurability = mInitialDurability;
    }
}
