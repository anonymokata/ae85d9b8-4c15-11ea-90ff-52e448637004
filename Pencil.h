#ifndef PENCILDURABILITYKATA_PENCIL_H
#define PENCILDURABILITYKATA_PENCIL_H

#include <string>

#include "Paper.h"

class Pencil
{
public:
    explicit Pencil(size_t durability = 10,
                    size_t length = 10,
                    size_t eraser_durability = 10);
    Pencil(const Pencil&) = delete;
    Pencil& operator=(const Pencil&) = delete;
    void write(Paper& paper, const std::string& new_text);
    void erase(Paper& paper, const std::string& to_erase);
    void sharpen();

private:
    char write(char character);
    std::string erase(const std::string& text);
    size_t mDurability;
    const size_t mInitialDurability;
    size_t mLength;
    size_t mEraserDurability;
};

#endif
