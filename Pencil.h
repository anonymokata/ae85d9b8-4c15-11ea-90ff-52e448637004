#ifndef PENCILDURABILITYKATA_PENCIL_H
#define PENCILDURABILITYKATA_PENCIL_H

#include <memory>
#include <string>

class Eraser;
class Paper;
class PencilPoint;

class Pencil
{
public:
    explicit Pencil(
            std::unique_ptr<PencilPoint> point = std::make_unique<PencilPoint>(),
            std::unique_ptr<Eraser> eraser = std::make_unique<Eraser>());
    Pencil(const Pencil&) = delete;
    Pencil& operator=(const Pencil&) = delete;
    void write(Paper& paper, const std::string& new_text);
    void erase(Paper& paper, const std::string& to_erase);
    void sharpen();

private:
    std::unique_ptr<PencilPoint> mPoint;
    std::unique_ptr<Eraser> mEraser;
};

#endif
