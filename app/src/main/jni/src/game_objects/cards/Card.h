//
// Created by anton on 2018-02-13.
//
#include <game_objects/DrawableEntity.h>
#include "../../Character.h"
#include "SDL.h"
#include "../../util/Graphics_manager.h"
#ifndef SDL_CARD_H
#define SDL_CARD_H
class Card: public DrawableEntity
{
//some art

public:

    virtual SDL_Texture* get_image()=0;
    void draw();

    SDL_Point center;
    SDL_Texture* img;
    SDL_Rect rect;
    int angle;


};
#endif //SDL_CARD_H
