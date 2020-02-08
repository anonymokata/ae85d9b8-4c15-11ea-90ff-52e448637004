#ifndef PENCILDURABILITYKATA_PAPER_H
#define PENCILDURABILITYKATA_PAPER_H

#include <string>

class Paper
{
public:
    [[nodiscard]] const std::string& get_text() const;

private:
    void write(const std::string& text);
    void erase_range(size_t from, size_t to);
    std::string mText;

    friend class Pencil;
};

#endif
