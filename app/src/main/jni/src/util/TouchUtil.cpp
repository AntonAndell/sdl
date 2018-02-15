//
// Created by anton on 2018-02-15.
//

#include "../../SDL2/include/SDL_rect.h"

SDL_Point normalize_position_to_pixels(SDL_Point touchLocation, SDL_Rect screen){
    touchLocation.x *=screen.w;
    touchLocation.y *=screen.h;
    return touchLocation;

}SDL_Point normalize_position_from_pixels(SDL_Point touchLocation, SDL_Rect screen){
    touchLocation.x /=screen.w;
    touchLocation.y /=screen.h;
    return touchLocation;
}
//touchlocation normalized between 0-1
bool contains(SDL_Rect* frame, SDL_Point touchLocation){
    if (frame->x <= touchLocation.x && touchLocation.x <= frame->x+frame->w){
        if (frame->y <= touchLocation.y && touchLocation.y <= frame->y+frame->h){
            return true;
        }
    }
    return false;

}