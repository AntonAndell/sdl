//
// Created by anton on 2018-02-13.
//

#include <util/TouchUtil.h>
#include "CardHolder.h"


double X=0.1;
double Y =0.6;
double WIDTH = 0.8;
double HEIGHT = 0.4;

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
void CardHolder::on_touch_down(SDL_Point touchlocation){
    SDL_Log("touch down");

}
void CardHolder::on_touch_up(SDL_Point touchlocation){
    SDL_Log("touch up");
}
void CardHolder::on_touch_move(SDL_Point touchlocation){
    SDL_Log("touch move");
}