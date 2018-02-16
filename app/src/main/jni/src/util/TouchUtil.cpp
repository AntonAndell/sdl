//
// Created by anton on 2018-02-15.
//
#include "TouchUtil.h"

int normalize_position_to_pixels_x(double x){
    return (int)(x*get_screen_size().w);
}
int normalize_position_to_pixels_y(double y){
    return (int)(y*get_screen_size().h);
}
double normalize_position_from_pixels_x(int x){
    return x/(double)get_screen_size().w;
}
double normalize_position_from_pixels_y(int x){
    return x/(double)get_screen_size().h;
}
SDL_Rect get_screen_size(){
    SDL_DisplayMode displayMode;
    SDL_Rect screen;
    if( SDL_GetCurrentDisplayMode( 0, &displayMode ) == 0 ) {
        screen.w = displayMode.w;
        screen.h = displayMode.h;
    }else {
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());
    }
    return screen;

}

//touchlocation in pixels
bool contains(SDL_Rect* frame, SDL_Point touchLocation){
    SDL_Log("frame x:%d frame y:%d\n", frame->x,frame->y );
    SDL_Log("touch x:%d touch y:%d\n", touchLocation.x,touchLocation.y );

    if ((frame->x <= touchLocation.x) && (touchLocation.x <= frame->x+frame->w)){
        if ((frame->y <= touchLocation.y) && (touchLocation.y <= frame->y+frame->h)){
            return true;
        }
    }
    return false;

}