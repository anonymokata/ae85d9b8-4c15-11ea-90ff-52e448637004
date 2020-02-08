#include "Eraser.h"

Eraser::Eraser(size_t durability)
        : mDurability(durability)
{
}

std::string Eraser::erase(const std::string& text)
{
    std::string result = text;
    for (auto it = result.rbegin(); it != result.rend(); ++it)
    {
        if (isspace(*it) || mDurability == 0)
            continue;
        else
        {
            *it = ' ';
            --mDurability;
        }
    }
    return result;
}

