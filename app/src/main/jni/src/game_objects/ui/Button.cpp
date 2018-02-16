//
// Created by anton on 2018-02-16.
//

#include "Button.h"
#include "../../../SDL2/include/SDL_log.h"

Button::Button() {
    frame = new SDL_Rect();
    frame->x= normalize_position_to_pixels_x(0.9);
    frame->y = normalize_position_to_pixels_y(0.6);
    frame->w = normalize_position_to_pixels_x(0.1);
    frame->h = normalize_position_to_pixels_y(0.3);
}
SDL_Rect* Button::get_frame() {
    return frame;
}
void Button::on_touch_down(SDL_Point touchlocation){
    SDL_Log("turn ended");
}
void Button::on_touch_up(SDL_Point touchlocation){
    SDL_Log("doing nothing");
}
void Button::on_touch_move(SDL_Point touchlocation){
    SDL_Log("should do something");
}