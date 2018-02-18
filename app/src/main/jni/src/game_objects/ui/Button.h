//
// Created by anton on 2018-02-16.
//

#ifndef SDL_BUTTON_H
#define SDL_BUTTON_H

#include "../Interactive.h"
#include "../../util/TouchUtil.h"

// TO BE SUPERCLASS
//testing one button now
class Button: public Interactive{
public:

    SDL_Rect* frame;
    SDL_Rect* get_frame();
    bool end_turn_state;
    Button();
    bool on_touch_down(SDL_Point touchlocation);
    void on_touch_up(SDL_Point touchlocation);
    void on_touch_move(SDL_Point touchlocation);
    bool moved_outside();

    bool end_turn();

    void reset();
};


#endif //SDL_BUTTON_H
