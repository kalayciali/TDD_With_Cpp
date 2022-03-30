#pragma once

#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_map>

#include "string_utils.h"

class Soundex
{
  public:
  static const size_t MAX_LENGTH{4};
  std::string clearWord(const std::string& word)
  {
    if (word.empty()) return pad(MAX_LENGTH);
    std::string clearedWord = std::string(1, std::toupper(word.front()));
    std::string tail = word.substr(1);
    dropVowelLikeLettersFrom(tail);
    clearedWord += tail;
    if (clearedWord.size() < MAX_LENGTH) padWord(clearedWord);
    return clearedWord;
  }
  std::string encode(const std::string& word)
  {
    std::string clearedWord = clearWord(word);
    return clearedWord;
  }

  private:
  const char PADDING = '0';
  std::string pad(int n) { return std::string(n, PADDING); }
  void padWord(std::string& word) { word += pad(MAX_LENGTH - word.size()); }
  void dropVowelLikeLettersFrom(std::string& word)
  {
    auto vowelLike = std::remove_if(word.begin(), word.end(), isVowel);
    word.erase(vowelLike, word.end());
  }
  std::string encodedDigit(char letter) const
  {
    const std::unordered_map<char, std::string> encodings{
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"},
        {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"}};
    auto it = encodings.find(letter);
    return it == encodings.end() ? "" : it->second;
  }
};

