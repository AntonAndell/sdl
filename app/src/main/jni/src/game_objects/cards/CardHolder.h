//
// Created by anton on 2018-02-13.
//
#include "../Interactive.h"
#include "Card.h"
#include <vector>
#include <game_objects/DrawableEntity.h>
#include "SDL.h"
#include "/util/TouchUtil.h"
#include "DeckHandler.h"

using namespace std;
#ifndef SDL_CARDHOLDER_H
#define SDL_CARDHOLDER_H


class CardHolder: public Interactive, public DrawableEntity {

private:
    DeckHandler* dh;
    // all in pixels
    void set_card_position( Card* c, int hand_size, int position,int height, int width);
public:
    void draw(SDL_Renderer*);
    vector<Card*> hand;
    SDL_Rect* frame;

    CardHolder();
    void next_turn();
    SDL_Rect* get_frame();
    bool on_touch_down(SDL_Point touchlocation);
    void on_touch_up(SDL_Point touchlocation);
    void on_touch_move(SDL_Point touchlocation);
    void set_deckHandler(DeckHandler* dh);
    void draw_card();
    bool moved_outside();


};


#endif //SDL_CARDHOLDER_H
