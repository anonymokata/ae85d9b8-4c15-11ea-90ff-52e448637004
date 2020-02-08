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
        if (mDurability == 0) break;

        if (!isspace(*it))
        {
            *it = ' ';
            --mDurability;
        }
    }
    return result;
}
