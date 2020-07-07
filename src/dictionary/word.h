//
// Created by Varsha Ramesh on 7/1/20.
//
#ifndef WORDGAME_WORD_H
#define WORDGAME_WORD_H

#endif //WORDGAME_WORD_H

#include <map>
#include <vector>
#include <string>
namespace dictionary {
    const std::vector<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
    class Word {
    private:
        std::string word;
        std::map<char, int> vowels;
        std::map<char, int> consonants;
    public:
        Word(std::string s);
        size_t length() const;
        size_t num_vowels() const;
        size_t num_consonants() const;
        const std::map<char, int>& get_vowels() const;
        const std::map<char, int>& get_consonants() const;
        bool contains(char) const;
        void print_word() const;
        std::string get() const;
        int compare(Word*) const;

    };
    inline bool operator==(const Word& lhs, const Word& rhs) {
        return lhs.get() == rhs.get();
    }

    struct WordComparator {
        bool operator()(const Word* lhs, const Word* rhs) {

            int val = lhs->get().compare(rhs->get());
            if(val == 0)
                return false;
            return val <= 0;
        }
    };

};
