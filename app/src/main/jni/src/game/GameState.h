//
// Created by alex on 2/14/2018.
//

#ifndef SDL_GAMESTATE_H
#define SDL_GAMESTATE_H


#include "../../SDL2/include/SDL_render.h"
#include "../../SDL2/include/SDL_events.h"

class GameState {
public:
    SDL_Texture* image;
    void update();
    void draw(SDL_Renderer* );
    void handleEvent(SDL_Event event);

    GameState();
    double x;
    double y;
};


#endif //SDL_GAMESTATE_H
