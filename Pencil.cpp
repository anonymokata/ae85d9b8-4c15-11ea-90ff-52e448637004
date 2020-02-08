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

Eraser::Eraser(size_t durability)
    : mDurability(durability)
{
}

std::string Eraser::erase(const std::string& text)
{
    if (text.size() > mDurability)
    {
        const auto characters_to_erase = mDurability;
        const auto characters_remaining = text.size() - mDurability;
        mDurability = 0;
        return text.substr(0, characters_remaining) +
               std::string(characters_to_erase, ' ');
    }
    else
    {
        mDurability -= text.size();
        return std::string(text.size(), ' ');
    }
}

Pencil::Pencil(size_t durability, size_t length, const Eraser& eraser)
    : mDurability(durability)
    , mInitialDurability(durability)
    , mLength(length)
    , mEraser(eraser)
{
}

void Pencil::write(Paper& paper, const std::string& new_text)
{
    std::string eroded_text;
    for (char c : new_text)
        eroded_text += write(c);
    paper.write(eroded_text);
}

std::string Pencil::erase(const std::string& text)
{
    return mEraser.erase(text);
}

void Pencil::erase(Paper& paper, const std::string& to_erase)
{
    const std::string& text = paper.get_text();
    const auto erase_from = text.rfind(to_erase);
    if (erase_from != std::string::npos)
    {
        const std::string erased_text = erase(to_erase);
        paper.replace_text(erase_from, erased_text);
    }
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
