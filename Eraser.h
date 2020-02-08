#ifndef PENCILDURABILITYKATA_ERASER_H
#define PENCILDURABILITYKATA_ERASER_H

#include <string>

class Eraser
{
public:
    explicit Eraser(size_t durability = 10);

    std::string erase(const std::string& text);

private:
    size_t mDurability;
};

#endif  // PENCILDURABILITYKATA_ERASER_H
