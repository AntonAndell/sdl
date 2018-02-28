//
// Created by anton on 2018-02-13.
//
#include "../Card.h"
#include "../../../../SDL2/src/render/SDL_sysrender.h"

#ifndef SDL_BLOCK_H
#define SDL_BLOCK_H


class Block: public Card{
    SDL_Texture* get_image();
    void Draw();
};


#endif //SDL_BLOCK_H
