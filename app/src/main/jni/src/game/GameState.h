//
// Created by alex on 2/14/2018.
//

#ifndef SDL_GAMESTATE_H
#define SDL_GAMESTATE_H


#include "../../SDL2/include/SDL_render.h"
#include "../../SDL2/include/SDL_events.h"
class GameState {
public:

    virtual void update();
    virtual void draw( );
    virtual void handleEvent(SDL_Event event);

    GameState();
};


#endif //SDL_GAMESTATE_H
