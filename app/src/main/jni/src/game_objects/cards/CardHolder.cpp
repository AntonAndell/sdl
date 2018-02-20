//
// Created by anton on 2018-02-13.
//

#include <util/TouchUtil.h>
#include "CardHolder.h"
#include <cmath>

double X=0.1;
double Y =0.6;
double WIDTH = 0.8;
double HEIGHT = 0.4;
double STANDARD_CARD_HEIGHT = 0.4;
double STANDARD_CARD_WIDTH = 0.15;

CardHolder::CardHolder() {
    frame = new SDL_Rect();
    frame->x= normalize_position_to_pixels_x(X);
    frame->y = normalize_position_to_pixels_y(Y);
    frame->w = normalize_position_to_pixels_x(WIDTH);
    frame->h = normalize_position_to_pixels_y(HEIGHT);
}
SDL_Rect* CardHolder::get_frame() {
    return frame;
}
bool CardHolder::on_touch_down(SDL_Point touchlocation){

    return true;
}
void CardHolder::on_touch_up(SDL_Point touchlocation){

}
void CardHolder::on_touch_move(SDL_Point touchlocation){

}
bool CardHolder::moved_outside(){

}

void CardHolder::set_deckHandler(DeckHandler* deckHandler) {
    dh=deckHandler;
}

void CardHolder::set_card_position(Card* c , int hand_size, int position, int height, int width){
    SDL_Rect rect;rect.h = width; rect.w = height;
    double c_center_x = 0.5;
    double c_center_y = 0.8;
    if(hand_size%2 == 0){
        position = position-(hand_size-2)/2;
        c_center_x += 0.07*position;
        c_center_y += abs(0.015*position);

        c->center.x = normalize_position_to_pixels_x(c_center_x);
        c->center.y = normalize_position_to_pixels_y(c_center_y);
        c->angle = +5*position;


    } else{
        position = position-(hand_size-1)/2;
        c_center_x += 0.07*position;
        c_center_y += abs(0.015*position);
        c->center.x = normalize_position_to_pixels_x(c_center_x);
        c->center.y = normalize_position_to_pixels_y(c_center_y);
        c->angle = +5*position;

    }
    rect.x= c->center.x-rect.w/2;
    rect.y = c->center.y-rect.h/2;
    c->rect = rect;
}
void CardHolder::draw_card() {
    hand.insert(hand.begin(), dh->get_next());
}

void CardHolder::draw(SDL_Renderer* r) {
    for(int i = 0; i<hand.size(); i++){
        set_card_position(hand[i], hand.size(), i, normalize_position_to_pixels_x(STANDARD_CARD_WIDTH), normalize_position_to_pixels_y(STANDARD_CARD_HEIGHT));
        hand[i]->draw(r);
    }
}

void CardHolder::next_turn() {
    draw_card();
}
