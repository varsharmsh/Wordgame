//
// Created by Varsha Ramesh on 7/2/20.
//

#include <string>
#include <fstream>
#include <iostream>
#include "dictionary.h"

using namespace dictionary;

Dictionary::Dictionary(std::string path) {
    srand((unsigned) time(0));
    std::ifstream in_file(path);
    if(!in_file) {
        std::cerr<<path<<" : invalid file"<<std::endl;
        exit(1);
    }
    build_index(in_file);
}

void Dictionary::build_index(std::ifstream& in_file) {
    std::string temp;
    while(getline(in_file, temp)) {
        Word* new_word = new Word(temp);
        for(char c : temp) {
            update_index(c, new_word);
        }
    }
}

void Dictionary::update_index(char c, Word* word) {
    word_list[c].insert(word);
}

size_t Dictionary::length() const {
    return word_list.size();
}

std::set<Word*, WordComparator> Dictionary::find_words(char c) {
    //use at instead of [] because it is const qualified
    return word_list[c];
}
void print_words(std::set<Word*, WordComparator> words) {
    for(Word* w : words) {
        w->print_word();
    }
    std::cout<<std::endl;
}
std::set<Word *, WordComparator> Dictionary::find_words(char c1, char c2) {
    return find_intersection(word_list[c1], word_list[c2]);
}

std::set<Word *, WordComparator> Dictionary::find_words(char c1, char c2, char c3) {
    std::set<Word*, WordComparator> intermediate = find_intersection(word_list.at(c1), word_list.at(c2));
    return find_intersection(intermediate, word_list[c3]);
}

std::set<Word *, WordComparator> Dictionary::find_words(char c1, char c2, char c3, char c4) {
    std::set<Word *, WordComparator> intermediate_1 = find_intersection(word_list[c1], word_list[c2]);
    std::set<Word *, WordComparator> intermediate_2 = find_intersection(word_list[c3], word_list[c4]);
    return find_intersection(intermediate_1, intermediate_2);
}

std::set<Word*, WordComparator>  Dictionary::find_intersection (std::set<Word*, WordComparator> s1, std::set<Word*, WordComparator> s2)  {
    std::set<Word*, WordComparator> result;
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(result, result.begin()), WordComparator());
    return result;
}

Word * Dictionary::get_random_word()  {
    char rand_char = rand()%26 + 97;
    int count = 0;
    while(count < MAX_RAND_WORDS_TRIES && word_list['a'].size() == 0){
        rand_char = rand()%26 + 97;
        count++;
    }
    if(count == MAX_RAND_WORDS_TRIES)
    {
        std::cerr<<"Unable to generate random word"<<std::endl;
        exit(1);
    }
    count = 0;
    int rand_word = rand()%word_list[rand_char].size();
    std::set<Word*, WordComparator>::iterator it = word_list[rand_char].begin();
    for(int i = 0; i < rand_word; i++)
        it++;
    return *it;
}
void Dictionary::print_index() {
    std::map<char, std::set<Word*, WordComparator>>::iterator it = word_list.begin();
    while(it != word_list.end()) {
        std::cout<<it->first;
        print_words(it->second);
        std::cout<<std::endl;
        it++;
    }
}