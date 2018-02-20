//
// Created by anton on 2018-02-18.
//

#ifndef SDL_DRAWABLEENTITY_H
#define SDL_DRAWABLEENTITY_H

#include <../../SDL2/include/SDL.h>
#include "../../SDL2/src/render/SDL_sysrender.h"


class DrawableEntity {
public:
    virtual void draw(SDL_Renderer* r) =0;
};


#endif //SDL_DRAWABLEENTITY_H
