#pragma once

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

class Soundex
{
  public:
  static const size_t MAX_LENGTH{4};

  std::string encode(const std::string& word)
  {
    if (word.empty()) return pad(MAX_LENGTH);
    std::string encodedWord = head(word);
    char lastEncoded = encodedWord.front();
    for (size_t i = 1; i < word.size(); ++i)
    {
      char digitNow = encodedDigit(word[i]);
      if (digitNow != PADDING && digitNow != lastEncoded )
      {
        encodedWord += digitNow;
        if (isMaxLength(encodedWord)) return encodedWord;
      }
      lastEncoded = digitNow;
    }
    padUntilMaxLength(encodedWord);
    return encodedWord;
  }

  private:
  const char PADDING = '0';
  std::string head(const std::string& word) const
  {
    return std::string(1, std::toupper(word.front()));
  }
  std::string pad(int n) const { return std::string(n, PADDING); }
  bool isMaxLength(const std::string& word) const
  {
    return (word.size() == MAX_LENGTH);
  }
  void padUntilMaxLength(std::string& word)
  {
    word += pad(MAX_LENGTH - word.size());
  }
  char encodedDigit(char letter) const
  {
    const std::unordered_map<char, char> encodings{
        {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'}, {'c', '2'}, {'g', '2'},
        {'j', '2'}, {'k', '2'}, {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
        {'d', '3'}, {'t', '3'}, {'l', '4'}, {'m', '5'}, {'n', '5'}, {'r', '6'}};
    auto it = encodings.find(std::tolower(letter));
    return it == encodings.end() ? PADDING : it->second;
  }
};

