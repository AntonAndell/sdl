//
// Created by anton on 2018-02-13.
//
#include "../Card.h"
#include "../../../../SDL2/include/SDL_render.h"
#include "../../../util/Graphics_manager.h"
#ifndef SDL_ATTACK_H
#define SDL_ATTACK_H


class Attack: public Card{

public:
    Attack();
    SDL_Texture* get_image();
};


#endif //SDL_ATTACK_H
