#include "Eraser.h"

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

