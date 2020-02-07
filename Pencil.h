#ifndef PENCILDURABILITYKATA_PENCIL_H
#define PENCILDURABILITYKATA_PENCIL_H

#include <string>

#include "Paper.h"

class Pencil
{
public:
    void write(Paper paper, const std::string& new_text);
};

#endif
