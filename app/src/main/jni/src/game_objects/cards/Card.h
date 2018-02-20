//
// Created by anton on 2018-02-13.
//
#include <game_objects/DrawableEntity.h>
#include "../../Character.h"
#include "SDL.h"
#ifndef SDL_CARD_H
#define SDL_CARD_H
class Card: public DrawableEntity
{
//some art

public:

    virtual SDL_Texture* get_image(SDL_Renderer*)=0;
    void draw(SDL_Renderer* r);

    SDL_Point center;
    SDL_Texture* img;
    SDL_Rect rect;
    int angle;


};
#endif //SDL_CARD_H
