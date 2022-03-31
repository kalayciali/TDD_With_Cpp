#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "soundex.h"

class SoundexEncoding : public testing::Test
{
  protected:
  Soundex soundex;
};

TEST_F(SoundexEncoding, FillWithPaddingIfEmpty) {
  ASSERT_EQ(soundex.encode(""), "0000");
}

TEST_F(SoundexEncoding, KeepOneLetterWord) {
  ASSERT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, EncodeConsonantsWithDigits) {
  ASSERT_EQ(soundex.encode("Dx"), "D200");
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
  ASSERT_EQ(soundex.encode("BaAeEiIoOuUhHyYcdl"), "B234");
}


TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
  ASSERT_EQ(soundex.encode("A#"), "A000");
}


TEST_F(SoundexEncoding, KeepHeadUppercase) {
  ASSERT_EQ(soundex.encode("sheahw"), "S000");
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants) {
  ASSERT_EQ(soundex.encode("BCDL"), soundex.encode("Bcdl"));
}

TEST_F(SoundexEncoding, TreatAsOneDigitIfTwoSameConsonant) {
  EXPECT_EQ(soundex.encode("Ab"), soundex.encode("Af"));
  EXPECT_EQ(soundex.encode("Ac"), soundex.encode("Ag"));
  EXPECT_EQ(soundex.encode("Ad"), soundex.encode("At"));
  ASSERT_EQ(soundex.encode("Abfcgdt"), "A123");
}

TEST_F(SoundexEncoding, StopWhenMaxLengthAchieved) {
  ASSERT_EQ(soundex.encode("baxxcdl"), "B234");
}

TEST_F(SoundexEncoding, DontTreatAsOneDigitIfSeparatedByVowelLike) {
  ASSERT_EQ(soundex.encode("Jbob"), "J110");
}
