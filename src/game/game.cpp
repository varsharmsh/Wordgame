//
// Created by Varsha Ramesh on 7/6/20.
//

#include "game.h"

using namespace game;

SinglePlayerGame::SinglePlayerGame(dictionary::Dictionary& dict) : Game(dict){
    target = dict.get_random_word();
}

GameResult SinglePlayerGame::play(std::string word) {
    dictionary::Word* played_word = new dictionary::Word(word);
    if(!dict.contains(played_word))
        return GameResult(played_word, PLAYING, -1, true, "Word not found in dictionary");
    if(played_word == target)
        return GameResult(played_word, WON, target->compare(played_word));
    return GameResult(new dictionary::Word(word), PLAYING, target->compare(played_word));
}