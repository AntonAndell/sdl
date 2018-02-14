//
// Created by alex on 2/14/2018.
//

#ifndef SDL_GAMESTATEMANAGER_H
#define SDL_GAMESTATEMANAGER_H


#include "GameState.h"
#include "../../SDL2/include/SDL_rect.h"
#include "../../SDL2/include/SDL_events.h"
#include "../../SDL2/src/render/SDL_sysrender.h"
#include <vector>

class GameStateManager {

public:
    void update();
    void draw(SDL_Renderer *renderer);
    void handleEvent(SDL_Event event);

    GameStateManager(SDL_Rect screen);
private:
    SDL_Rect screenRect;
    std::vector<GameState*> gamestates;
    int currentIndex;

};


#endif //SDL_GAMESTATEMANAGER_H
