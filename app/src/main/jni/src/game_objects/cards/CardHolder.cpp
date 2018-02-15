//
// Created by anton on 2018-02-13.
//

#include "CardHolder.h"


double X=0;
double Y = 0.1;
double WIDTH = 0.3;
double HEIGHT = 0.8;

CardHolder::CardHolder() {
    frame = new SDL_Rect();
    frame->x=X;
    frame->y = Y;
    frame->w = WIDTH;
    frame->h = HEIGHT;
}
SDL_Rect* CardHolder::get_frame() {
    return frame;
}
void CardHolder::on_touch_down(SDL_Point touchlocation){
    SDL_Log("touch down");

}
void CardHolder::on_touch_up(SDL_Point touchlocation){
    SDL_Log("touch up");
}
void CardHolder::on_touch_move(SDL_Point touchlocation){
    SDL_Log("touch move");
}