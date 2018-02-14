//
// Created by alex on 2/14/2018.
//
extern "C"
{
#include "SDL.h"
}
#include "GameStateManager.h"


#ifndef SDL_GAME_H
#define SDL_GAME_H
#endif //SDL_GAME_H

class Game {
public:
    int WIDTH;
    int HEIGHT;
    GameStateManager *gsm;

    SDL_Point touchLocation;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect screenRect;
    SDL_Event event;

    bool running;

    void gameLoop();
    void update();
    void draw();
    void handleInput();
    void init();

    Game();
};

