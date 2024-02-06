#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "Lib.h"

void clean_text(std::string &text)
{
    replace_all(text, ",", "");
    replace_all(text, ".", "");
    replace_all(text, "!", "");
    replace_all(text, "?", "");
    replace_all(text, "\n", "");
    replace_all(text, "\t", "");

}

void replace_all(std::string &text, std::string_view what, std::string_view with)
{
    for (std::size_t pos = 0; pos != std::string::npos; pos += with.length())
    {
        pos = text.find(what.data(), pos, what.length());
        if (pos != std::string::npos)
        {
            text.replace(pos, what.length(), with.data(), with.length());
        }
    }

}

std::vector<std::string> split_text(const std::string &text, char delimiter)
{
    if (text.empty())
    {
        std::cout << "empty text data" << std::endl;
    }
        std::vector<std::string> tempVec{};
        auto iss = std::istringstream{text};
        std::string tempItem{};
        while (std::getline(iss, tempItem, delimiter))
        {

            tempVec.push_back(tempItem);
        }

    return tempVec;
}
