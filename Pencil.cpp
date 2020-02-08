#include "Pencil.h"

#include <stdexcept>

#include "Eraser.h"
#include "Paper.h"

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

Pencil::Pencil(size_t durability, size_t length, std::unique_ptr<Eraser> eraser)
    : mDurability(durability)
    , mInitialDurability(durability)
    , mLength(length)
    , mEraser(std::move(eraser))
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
    return mEraser->erase(text);
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
