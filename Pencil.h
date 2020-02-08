#ifndef PENCILDURABILITYKATA_PENCIL_H
#define PENCILDURABILITYKATA_PENCIL_H

#include <memory>
#include <string>

class Eraser;
class Paper;

class PencilPoint
{
public:
    explicit PencilPoint(size_t durability = 10);
    std::string write(const std::string& to_write);
    void sharpen();

private:
    size_t mDurability;
    const size_t mInitialDurability;

private:
    char write(char character);
};

class Pencil
{
public:
    explicit Pencil(
            size_t durability = 10,
            size_t length = 10,
            std::unique_ptr<Eraser> eraser = std::make_unique<Eraser>());
    Pencil(const Pencil&) = delete;
    Pencil& operator=(const Pencil&) = delete;
    void write(Paper& paper, const std::string& new_text);
    void erase(Paper& paper, const std::string& to_erase);
    void sharpen();

private:
    size_t mLength;
    PencilPoint mPoint;
    std::unique_ptr<Eraser> mEraser;
};

#endif
