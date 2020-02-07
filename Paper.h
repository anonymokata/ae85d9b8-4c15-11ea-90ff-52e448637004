#ifndef PENCILDURABILITYKATA_PAPER_H
#define PENCILDURABILITYKATA_PAPER_H

#include <string>

class Paper
{
public:
    const std::string& get_text() const;

private:
    std::string mText;
};

#endif
