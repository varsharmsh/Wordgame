#include <iostream>

#include "dictionary/dictionary.h"
#include <set>

using namespace dictionary;
using namespace std;

int main() {

    dictionary::Dictionary my_dict("/Users/varamesh/CLionProjects/WordGame/data/4letters.txt");
    dictionary::Word word("abcd");
    map<char, int> vowels = word.get_vowels();
    for(int i = 0; i < 10; i++)
        cout<<my_dict.get_random_word()->get()<<endl;

}