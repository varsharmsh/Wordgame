//
// Created by Varsha Ramesh on 7/1/20.
//

#include <string>
#include <iostream>
#include "word.h"

using namespace dictionary;


Word::Word(std::string s) {
       word.resize(s.length());
       transform(s.begin(), s.end(), word.begin(), tolower);
       for(char c : word) {
           if(std::find(VOWELS.begin(), VOWELS.end(), c) != VOWELS.end()) {
               if(vowels.find(c) == vowels.end())
                   vowels.insert(std::pair<char, int>(c, 0));
               vowels[c]++;
           }
           else {
               if(consonants.find(c) == consonants.end())
                   consonants.insert(std::pair<char, int>(c, 0));
               consonants[c]++;
           }
       }
}

size_t Word::length() const {
    return word.length();
}

size_t Word::num_vowels() const {
    return vowels.size();
}

size_t Word::num_consonants() const {
    return consonants.size();
}

const std::map<char,int>& Word::get_vowels() const {
    return vowels;
}

const std::map<char, int>& Word::get_consonants() const {
    return consonants;
}

void Word::print_word() const{
    std::cout<<"["<<word<<"]";
}

bool Word::contains(char c) const {
    return word.find(c) != std::string::npos;
}

std::string Word::get() const {
    return word;
}

int Word::compare(Word * other) const {
    int count = 0;
    std::map<char, int>vowels = get_vowels();
    std::map<char, int>other_vowels = other->get_vowels();
    std::map<char,int>::iterator vowels_it_other = other_vowels.begin();
    while(vowels_it_other != other_vowels.end()) {
        std::map<char,int>::iterator it = vowels.find(vowels_it_other->first);
        if(it != vowels.end())
            count++;
        vowels_it_other++;
    }
    std::map<char, int>consonants = get_consonants();
    std::map<char, int>other_consonants = other->get_consonants();
    std::map<char, int>::iterator consonants_it_other = other_consonants.begin();
    while(consonants_it_other != other_consonants.end()) {
        std::map<char,int>::iterator it = consonants.find(consonants_it_other->first);
        if(it != consonants.end())
            count++;

        consonants_it_other++;
    }
    return count;
}