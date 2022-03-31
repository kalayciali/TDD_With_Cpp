# Soundex Algorithm Implementation

1. Retain the first letter. Drop all other occurrences of a, e, i, o, u, y, h, w.

2. Replace consonants with digits (after the first letter):
    - b, f, p, v: 1
    - c, g, j, k, q, s, x, z: 2
    - d, t : 3
    - l: 4
    - m, n: 5
    - r:

3. If two adjacent letters encode to the same number, encode them instead
as a single number. Also, do so if two letters with the same number are
separated by h or w (but code them twice if separated by a vowel). This
rule also applies to the first letter.

4. Stop when you have a letter and three digits. Zero-pad if needed.


## Implementation Considerations

- For first time, I have tried to first clear word from unnecessary letters which was wrong way of doing things.
By doing it, I m throw off the information of where vowel like letters are.
Since there could be a situation where two consonant separated by vowellike.

- With this configuration, nearly similar to what was implemented in book, we are encoding everything other than consonants
to padding, so we could throw it after encoded.

- I'll move on. This was my first try of TDD.
