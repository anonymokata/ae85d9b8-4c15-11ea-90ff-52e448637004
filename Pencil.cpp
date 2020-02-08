#include "Pencil.h"

#include <stdexcept>

#include "Eraser.h"
#include "Paper.h"
#include "PencilPoint.h"

Pencil::Pencil(std::unique_ptr<PencilPoint> point,
               std::unique_ptr<Eraser> eraser)
    : mPoint(std::move(point))
    , mEraser(std::move(eraser))
{
}

void Pencil::write(Paper& paper, const std::string& new_text)
{
    const std::string to_write = mPoint->write(new_text);
    paper.write(to_write);
}

void Pencil::erase(Paper& paper, const std::string& to_erase)
{
    const std::string& text = paper.get_text();
    const auto erase_from = text.rfind(to_erase);
    if (erase_from != std::string::npos)
    {
        const std::string erased_text = mEraser->erase(to_erase);
        paper.replace_text(erase_from, erased_text);
    }
}

void Pencil::sharpen()
{
    mPoint->sharpen();
}
