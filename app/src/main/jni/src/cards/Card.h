//
// Created by anton on 2018-02-13.
//
#include "../Character.h"
#ifndef SDL_CARD_H
#define SDL_CARD_H
class Card
{
//some art

public:
    Card();
    virtual bool use(Character hero, Character Opponent);
};
#endif //SDL_CARD_H
