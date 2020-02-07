#ifndef PENCILDURABILITYKATA_PAPER_H
#define PENCILDURABILITYKATA_PAPER_H

#include <string>

class Paper
{
public:
    const std::string& get_text() const;

    void write(const std::string& text);

private:
    std::string mText;
};

#endif
