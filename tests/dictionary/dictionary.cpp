//
// Created by Varsha Ramesh on 7/4/20.
//

#include <fstream>
#include "dictionary/dictionary.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace dictionary;
using testing::ElementsAre;
using testing::Pointee;

TEST(DictionaryTest, constructionTest) {
    std::ofstream file("./test-file");
    std::string text = "hello\nhow\nare\nyou\n";
    file.write(text.c_str(), text.length());
    file.close();
    ASSERT_NO_THROW(Dictionary("./test-file"));
    remove("./test-file");
    ASSERT_DEATH( Dictionary("invalid-file"), "invalid-file : invalid file");
}

TEST(DictionaryTest, indexTest) {
    std::ofstream file("./test-file");
    std::string text = "hello\nhow\nare\nyou\n";
    file.write(text.c_str(), text.length());
    file.close();
    Dictionary d = Dictionary("./test-file");
    ASSERT_EQ(d.length(), 9);
    //ASSERT_THAT(d.find_words('x'), ElementsAre());
    ASSERT_THAT(d.find_words('a'), ElementsAre(Pointee(Word("are"))));
    ASSERT_THAT(d.find_words('e'), ElementsAre(Pointee(Word("are")), Pointee(Word("hello"))));
    ASSERT_THAT(d.find_words('h'), ElementsAre(Pointee(Word("hello")), Pointee(Word("how"))));
    ASSERT_THAT(d.find_words('l'), ElementsAre(Pointee(Word("hello"))));
    ASSERT_THAT(d.find_words('h'), ElementsAre(Pointee(Word("hello")), Pointee(Word("how"))));
    ASSERT_THAT(d.find_words('r'), ElementsAre(Pointee(Word("are"))));
    ASSERT_THAT(d.find_words('u'), ElementsAre(Pointee(Word("you"))));
    ASSERT_THAT(d.find_words('w'), ElementsAre(Pointee(Word("how"))));
    ASSERT_THAT(d.find_words('y'), ElementsAre(Pointee(Word("you"))));
    remove("./test-file");
}

TEST(DictionaryTest, intersectionTest) {
    std::ofstream file("./test-file");
    std::string text = "hello\nhow\nare\nyou\ncello\ngrain\nrain\n";
    file.write(text.c_str(), text.length());
    file.close();

    Dictionary d = Dictionary("./test-file");
    ASSERT_EQ(d.length(), 13);
    ASSERT_THAT(d.find_words('h', 'o'), ElementsAre(Pointee(Word("hello")), Pointee(Word("how"))));
    ASSERT_THAT(d.find_words('e', 'l', 'o'), ElementsAre(Pointee(Word("cello")), Pointee(Word("hello"))));
    ASSERT_THAT(d.find_words('i', 'r', 'a', 'n'), ElementsAre(Pointee(Word("grain")), Pointee(Word("rain"))));
    remove("./test-file");
}
