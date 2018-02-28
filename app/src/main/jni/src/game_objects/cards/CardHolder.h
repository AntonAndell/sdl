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

struct old_card_pos{
    SDL_Rect old_rect;
    int angle;
    Card* c;

};
class CardHolder: public Interactive, public DrawableEntity {

private:
    old_card_pos ocp;
    DeckHandler* dh;
    // all in pixels
    void set_card_position( Card* c, int hand_size, int position,int height, int width);
public:
    void draw();
    vector<Card*> hand;
    SDL_Rect* frame;

    CardHolder();
    void next_turn();
    SDL_Rect* get_frame();
    bool on_touch_down(SDL_Point touchlocation);
    bool on_touch_up(SDL_Point touchlocation, bool outside);
    bool on_touch_move(SDL_Point touchlocation, bool outside);
    void set_deckHandler(DeckHandler* dh);
    void draw_card();
    bool moved_outside();


};


#endif //SDL_CARDHOLDER_H
