#ifndef PENCILDURABILITYKATA_PENCIL_H
#define PENCILDURABILITYKATA_PENCIL_H

#include <string>

#include "Paper.h"

class Pencil
{
public:
    explicit Pencil(size_t durability = 10, size_t length = 10);
    void write(Paper& paper, const std::string& new_text);
    void sharpen();

private:
    char write(char character);
    size_t mDurability;
    size_t mInitialDurability;
    size_t mLength;
};

#endif
