//
// Created by Varsha Ramesh on 7/6/20.
//
/*
#include <dictionary/dictionary.h>
#include <string>

#ifndef WORDGAME_GAME_H
#define WORDGAME_GAME_H

#endif //WORDGAME_GAME_H

namespace game {
    enum GameState {PLAYING, TERMINATED, WON, FAILED};
    class GameResult {
    public:
        GameState state;
        dictionary::Word* played_word;
        bool is_error;
        std::string error_desc;
        GameResult(dictionary::Word*, GameState, int, bool is_error = false, std::string error_desc = "");

    };
    class Game {
    private:
        dictionary::Dictionary dict;
    public:
        Game(dictionary::Dictionary& d) : dict(d){}
        virtual GameResult play(std::string) = 0;
    };
    class SinglePlayerGame: public Game{
    private:
        dictionary::Word* target;
    public:
        SinglePlayerGame(dictionary::Dictionary&);
        GameResult play(std::string);
    };

}*/