#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "Lib.h"

void clean_text(std::string &text)
{
    size_t position = 0; // Startposition für die Suche
    while ((position = text.find(",", position)) != std::string::npos)
    {
        text.erase(position, 1); // Entfernt 1 Zeichen an der Position 'position'
    }
}

void replace_all(std::string &text, std::string_view what, std::string_view with)
{
}

std::vector<std::string> split_text(const std::string &text, char delimiter)
{
}
