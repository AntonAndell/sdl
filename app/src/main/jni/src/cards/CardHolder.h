//
// Created by anton on 2018-02-13.
//
#include "Card.h"
#include <vector>

using namespace std;
#ifndef SDL_CARDHOLDER_H
#define SDL_CARDHOLDER_H


class CardHolder {
    vector<Card> hand;
public:
    void draw();
};


#endif //SDL_CARDHOLDER_H
