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
    //temporary, to be sent o specifik gamestate
    eventHandler = new EventHandler();
    CardHolder* ch = new CardHolder();
    eventHandler->add_interactive(ch);
}

void GameStateManager::update() {
    gamestates[currentIndex]->update();
}

void GameStateManager::draw(SDL_Renderer *renderer) {
    gamestates[currentIndex]->draw(renderer);
}

void GameStateManager::handleEvent(SDL_Event event) {
    if (event.type == SDL_FINGERDOWN ){
        SDL_Point t;
        t.x = event.tfinger.x;
        t.y = event.tfinger.y;
        Interactive* i = eventHandler->get_touched_interactive(t);
        i->on_touch_down(t);
    }
    if (event.type == SDL_FINGERMOTION ){
        SDL_Point t;
        t.x = event.tfinger.x;
        t.y = event.tfinger.y;
        Interactive* i = eventHandler->get_touched_interactive(t);
        i->on_touch_move(t);
    }
    if (event.type == SDL_FINGERUP ){
        SDL_Point t;
        t.x = event.tfinger.x;
        t.y = event.tfinger.y;
        Interactive* i = eventHandler->get_touched_interactive(t);
        i->on_touch_up(t);

    }
}