//
// Created by Varsha Ramesh on 7/2/20.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "dictionary/word.h"


using namespace dictionary;

using testing::ElementsAre;
using testing::Pair;
using testing::IsEmpty;

TEST(WordTest, constructionTest) {
    ASSERT_EQ(Word("something").get(), "something");
    ASSERT_EQ(Word("").get(), "");
    ASSERT_EQ(Word("hello"), Word("hello"));
}

TEST(WordTest, vowelsTest) {
    ASSERT_EQ(Word("abcd").num_vowels(), 1);
    ASSERT_EQ(Word("abcde").num_vowels(), 2);
    ASSERT_EQ(Word("aeiou").num_vowels(), 5);
    ASSERT_EQ(Word("AEIOU").num_vowels(), 5);
    ASSERT_THAT(Word("abcd").get_vowels(), ElementsAre(Pair('a',1)));
    ASSERT_THAT(Word("abcde").get_vowels(), ElementsAre(Pair('a',1), Pair('e', 1)));
    ASSERT_THAT(Word("aeiou").get_vowels(), ElementsAre(
            Pair('a',1), Pair('e', 1), Pair('i', 1), Pair('o', 1), Pair('u',1)));
    ASSERT_THAT(Word("AEIOU").get_vowels(), ElementsAre(
            Pair('a',1), Pair('e', 1), Pair('i', 1), Pair('o', 1), Pair('u',1)));
    ASSERT_THAT(Word("aaeei").get_vowels(), ElementsAre(
            Pair('a',2), Pair('e', 2), Pair('i', 1)));
    ASSERT_THAT(Word("AAEEI").get_vowels(), ElementsAre(
            Pair('a',2), Pair('e', 2), Pair('i', 1)));
    ASSERT_THAT(Word("bcd").get_vowels(), IsEmpty());
}

TEST(WordTest, consonantsTest) {
    ASSERT_EQ(Word("abcd").num_consonants(), 3);
    ASSERT_EQ(Word("abcde").num_consonants(), 3);
    ASSERT_EQ(Word("aeiou").num_consonants(), 0);
    ASSERT_EQ(Word("BCDF").num_consonants(), 4);
    ASSERT_THAT(Word("abei").get_consonants(), ElementsAre(Pair('b',1)));
    ASSERT_THAT(Word("abce").get_consonants(), ElementsAre(Pair('b',1), Pair('c', 1)));
    ASSERT_THAT(Word("BCD").get_consonants(), ElementsAre(Pair('b',1), Pair('c', 1), Pair('d',1)));
    ASSERT_THAT(Word("BBBCC").get_consonants(), ElementsAre(Pair('b',3), Pair('c', 2)));
    ASSERT_THAT(Word("bbbcc").get_consonants(), ElementsAre(Pair('b',3), Pair('c', 2)));
    ASSERT_THAT(Word("aeio").get_consonants(), IsEmpty());
}

TEST(WordTest, comparisonTest) {
    ASSERT_EQ(Word("hello"), Word("hello"));
    ASSERT_EQ(Word(""), Word(""));
    ASSERT_EQ(Word("HELLO"), Word("hellO"));

    ASSERT_EQ(Word("abcd").compare(new Word("abcd")), 4);
    ASSERT_EQ(Word("abcd").compare(new Word("abbd")), 3);
    ASSERT_EQ(Word("abcd").compare(new Word("xyzf")), 0);
    ASSERT_EQ(Word("hello").compare(new Word("helo")), 4);

}

TEST(WordTest, pointerComparisonTest) {
    ASSERT_FALSE(WordComparator()(new Word("hello"), new Word("hello")));
    ASSERT_FALSE(WordComparator()(new Word("hello"), new Word("HELLO")));
    ASSERT_TRUE(WordComparator()(new Word("abcd"), new Word("bcde")));
    ASSERT_FALSE(WordComparator()(new Word("bcde"), new Word("abcd")));
}

