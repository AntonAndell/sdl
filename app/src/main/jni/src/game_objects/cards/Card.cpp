//
// Created by anton on 2018-02-13.
//
#include "Card.h"
#include "../../../SDL2/src/render/SDL_sysrender.h"
#include "../../../SDL2/include/SDL_render.h"



void Card::draw(SDL_Renderer* r) {

    if (get_image(r)==0){
        SDL_Log("nope biaaatch");
    }
    SDL_RenderCopyEx(r,get_image(r), NULL, &rect,angle,NULL,SDL_FLIP_NONE);
}



