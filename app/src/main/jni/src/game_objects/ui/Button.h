//
// Created by anton on 2018-02-16.
//

#ifndef SDL_BUTTON_H
#define SDL_BUTTON_H

#include "../Interactive.h"
#include "../../util/TouchUtil.h"

// TO BE SUPERCLASS
//testing one button now
class Button: public Interactive {
public:

    SDL_Rect* frame;
    SDL_Rect* get_frame();
    Button();
    void on_touch_down(SDL_Point touchlocation);
    void on_touch_up(SDL_Point touchlocation);
    void on_touch_move(SDL_Point touchlocation);
};


#endif //SDL_BUTTON_H
