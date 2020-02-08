#ifndef PENCILDURABILITYKATA_PAPER_H
#define PENCILDURABILITYKATA_PAPER_H

#include <string>

class Paper
{
public:
    [[nodiscard]] const std::string& get_text() const;

private:
    void write(const std::string& text);
    void replace_text(size_t from, const std::string& replacement);
    void edit(size_t position, const std::string& new_text);

    std::string mText;

    friend class Pencil;
};

#endif
