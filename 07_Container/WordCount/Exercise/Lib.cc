#include <algorithm>
#include <filesystem>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>

#include "Lib.h"

void clean_text(std::string &text)
{
    replace_all(text, ".", "");
    replace_all(text, ",", "");
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

WordVector split_text(const std::string &text, char delimiter)
{
    auto words = WordVector{};

    auto iss = std::istringstream{text};
    auto item = std::string{};

    while (std::getline(iss, item, delimiter))
    {
        words.push_back(item);
    }

    return words;
}

std::map<std::string, std::size_t> count_words(const WordVector &words)
{
    std::map<std::string, std::size_t> tempMap{};
    for (const auto &item : words)
    {
        tempMap[item]++;
    }
    return tempMap;
}

std::vector<std::pair<std::string, std::size_t>> map_to_vector(const std::map<std::string, std::size_t> &counted_words)
{
    std::vector<std::pair<std::string, std::size_t>> tempVecPair;
    for (const auto &item : counted_words)
    {
        tempVecPair.push_back(item);
    }
    return tempVecPair;
}

//NOTE compare function is for display only, they doesn`t needed while use lambda-expression
bool compare(const std::pair<std::string, std::size_t> &pair1, const std::pair<std::string, std::size_t> &pair2)
{
    return pair1.second > pair2.second;
}

void sort_word_counts(WordCountVec &word_counts)
{
    std::sort(word_counts.begin(), word_counts.end(), [](std::pair<std::string, std::size_t> &a, std::pair<std::string, std::size_t> &b)
    {
        return a.second > b.second;
    });
}
