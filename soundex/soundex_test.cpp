#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "soundex.h"

class SoundexEncoding : public testing::Test
{
  protected:
  Soundex soundex;
};

TEST_F(SoundexEncoding, FillWithPaddingIfEmpty) {
  ASSERT_EQ(soundex.clearWord(""), "0000");
}

TEST_F(SoundexEncoding, KeepOneLetterWord) {
  ASSERT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, FillWithPaddingIfLessThanMaxLength) {
  ASSERT_EQ(soundex.clearWord("Ab"), "Ab00");
}

TEST_F(SoundexEncoding, DropVowelLikeLettersCaseInsensitive) {
  ASSERT_EQ(soundex.clearWord("AceahwyAeIou"), "Ac00");
}

TEST_F(SoundexEncoding, KeepHeadUppercase) {
  ASSERT_EQ(soundex.clearWord("sheahw"), "S000");
}

TEST_F(SoundexEncoding, DISABLED_ReplaceConsonantsWithDigits) {
  ASSERT_EQ(soundex.encode("Dx"), "D200");
}
