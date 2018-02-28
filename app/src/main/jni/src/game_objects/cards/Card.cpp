//
// Created by anton on 2018-02-13.
//
#include "Card.h"
#include "../../../SDL2/src/render/SDL_sysrender.h"
#include "../../../SDL2/include/SDL_render.h"



void Card::draw() {
    render_ex(get_image(), rect,angle);
}



