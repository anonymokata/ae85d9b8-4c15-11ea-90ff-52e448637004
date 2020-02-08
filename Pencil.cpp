#include "Pencil.h"

namespace
{
size_t calculate_new_durability(char character, size_t old_durability)
{
    size_t new_durability = old_durability;
    if (isupper(character))
        new_durability -= 2;
    else
        new_durability -= 1;

    if (new_durability == static_cast<size_t>(-1))
        new_durability = 0;
    return new_durability;
}
}

Pencil::Pencil(size_t durability)
    : mDurability(durability)
{
}

void Pencil::write(Paper& paper, const std::string& new_text)
{
    std::string eroded_text;
    for (char c : new_text)
        eroded_text += write(c);
    paper.write(eroded_text);
}

char Pencil::write(char character)
{
    if (mDurability > 0)
    {
        mDurability = calculate_new_durability(character, mDurability);
        return character;
    }
    else
        return isspace(character) ? character : ' ';
}
