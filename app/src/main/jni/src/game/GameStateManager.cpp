//
// Created by alex on 2/14/2018.
//

#include "GameStateManager.h"
#include "../../SDL2/src/render/SDL_sysrender.h"
#include "BattleState.h"

GameStateManager::GameStateManager(SDL_Rect screen) {
    screenRect = screen;

    GameState* state = new BattleState();
    gamestates.push_back(state);

    currentIndex = 0;
    //temporary, to be sent o specific gamestate

    //end temporary
}

void GameStateManager::update() {
    gamestates[currentIndex]->update();
}

void GameStateManager::draw() {
    gamestates[currentIndex]->draw();
}

void GameStateManager::handleEvent(SDL_Event event) {
    gamestates[currentIndex]->handleEvent(event);

}