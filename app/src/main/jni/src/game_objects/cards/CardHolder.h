//
// Created by anton on 2018-02-13.
//
#include "../Interactive.h"
#include "Card.h"
#include <vector>
#include "SDL.h"
#include "/util/TouchUtil.h"

using namespace std;
#ifndef SDL_CARDHOLDER_H
#define SDL_CARDHOLDER_H


class CardHolder: public Interactive {


public:
    void draw();
    vector<Card> hand;
    SDL_Rect* frame;
    CardHolder();
    SDL_Rect* get_frame();
    bool on_touch_down(SDL_Point touchlocation);
    void on_touch_up(SDL_Point touchlocation);
    void on_touch_move(SDL_Point touchlocation);
    bool moved_outside();
};


#endif //SDL_CARDHOLDER_H
