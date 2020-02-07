#include "Pencil.h"

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
        return character;
    else
        return isspace(character) ? character : ' ';
}
