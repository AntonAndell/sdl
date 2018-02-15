//
// Created by anton on 2018-02-15.
//

#ifndef SDL_INTERACTIVE_H
#define SDL_INTERACTIVE_H


#include "../../SDL2/include/SDL_rect.h"

class Interactive {
public:
    //the area which it occupies
    virtual SDL_Rect* get_frame() =0;

    virtual void on_touch_down(SDL_Point touchlocation)=0;
    virtual void on_touch_up(SDL_Point touchlocation)=0;
    virtual void on_touch_move(SDL_Point touchlocation)=0;
};


#endif //SDL_INTERACTIVE_H
