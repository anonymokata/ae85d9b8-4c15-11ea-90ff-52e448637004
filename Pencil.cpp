#include "Pencil.h"

Pencil::Pencil(size_t durability)
{
}

void Pencil::write(Paper& paper, const std::string& new_text)
{
    paper.write(new_text);
}
