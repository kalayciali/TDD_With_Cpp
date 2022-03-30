#include "string_utils.h"
#include <cctype>

bool isVowel(char c)
{
  c = std::tolower(c);
  switch (c)
  {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
    case 'h':
    case 'w':
      return true;
    default:
      return false;
  }
}
