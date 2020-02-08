#ifndef PENCILDURABILITYKATA_PENCILPOINT_H
#define PENCILDURABILITYKATA_PENCILPOINT_H

#include <string>

class PencilPoint
{
public:
    explicit PencilPoint(size_t durability = 20, size_t length = 10);
    std::string write(const std::string& to_write);
    void sharpen();

private:
    char write(char character);

    size_t mDurability;
    const size_t mInitialDurability;
    size_t mLength;

};

#endif  // PENCILDURABILITYKATA_PENCILPOINT_H
