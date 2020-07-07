//
// Created by Varsha Ramesh on 7/2/20.
//

#include "word.h"
#include <set>
#ifndef WORDGAME_DICTIONARY_H
#define WORDGAME_DICTIONARY_H

#endif //WORDGAME_DICTIONARY_H

namespace dictionary {
    class Dictionary {
    private:
        int MAX_RAND_WORDS_TRIES = 5;
        std::map<char, std::set<Word*, WordComparator>> word_list;
        void build_index(std::ifstream&);
        void update_index(char, Word*);
        std::set<Word *, WordComparator> find_intersection(std::set<Word *, WordComparator>, std::set<Word *, WordComparator>);
    public:
        size_t length() const;
        std::set<Word *, WordComparator> find_words(char);
        std::set<Word *, WordComparator> find_words(char, char);
        std::set<Word *, WordComparator> find_words(char, char, char);
        std::set<Word *, WordComparator> find_words(char, char, char, char);
        Dictionary(std::string path);

        void print_index();
        Word * get_random_word();

        bool contains(Word *word);
    };
}