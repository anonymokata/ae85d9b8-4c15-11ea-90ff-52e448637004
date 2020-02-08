#ifndef PENCILDURABILITYKATA_PENCIL_H
#define PENCILDURABILITYKATA_PENCIL_H

#include <memory>
#include <string>

class Eraser;
class Paper;

class Pencil
{
public:
    explicit Pencil(size_t durability = 10,
                    size_t length = 10,
                    std::unique_ptr<Eraser> eraser = std::make_unique<Eraser>());
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
    std::unique_ptr<Eraser> mEraser;
};

#endif
