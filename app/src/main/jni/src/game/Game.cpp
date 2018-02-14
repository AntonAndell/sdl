//
// Created by alex on 2/14/2018.
//
#include "Game.h"
#include "../../SDL2/include/SDL.h"

Game::Game(void){
    init();

    running = true;
    gameLoop();
}

void Game::init(){
    SDL_VideoInit(NULL);
    SDL_DisplayMode displayMode;
    if( SDL_GetCurrentDisplayMode( 0, &displayMode ) == 0 ) {
        screenRect.w = displayMode.w;
        screenRect.h = displayMode.h;
    }else{
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());

    }
    //creates window and does first render
    if (SDL_CreateWindowAndRenderer(screenRect.w, screenRect.h, 0, &window, &renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL_CreateWindowAndRenderer() failed: %s", SDL_GetError());
    }


    SDL_SetWindowSize(window, 800, 480);
    gsm = new GameStateManager(screenRect);
    SDL_RenderClear( renderer );
}

void Game::draw() {
    gsm->draw(renderer);
}

void Game::gameLoop(){
    while(running){
        handleInput();
        update();
        draw();
    }
}

void Game::handleInput() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            running = false;

        gsm->handleEvent(event);
    }
}

void Game::update(){
    gsm->update();
}