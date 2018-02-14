//
// Created by alex on 2/14/2018.
//
#include "GameStateManager.h"
#include "../../SDL2/src/render/SDL_sysrender.h"

GameStateManager::GameStateManager(SDL_Rect screen) {
    screenRect = screen;

    GameState* state = new GameState();
    gamestates.push_back(state);
    currentIndex = 0;
}

void GameStateManager::update() {
    gamestates[currentIndex]->update();
}

void GameStateManager::draw(SDL_Renderer *renderer) {
    gamestates[currentIndex]->draw(renderer);
}

void GameStateManager::handleEvent(SDL_Event event) {

    if (event.type == SDL_FINGERDOWN ){
    }
    if (event.type == SDL_FINGERMOTION ){
    }
    if (event.type == SDL_FINGERUP ){
    }
}