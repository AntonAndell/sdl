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
    //temporary, to be sent o specific gamestate
    eventHandler = new EventHandler();
    Button* b = new Button();
    state->b = b;
    CardHolder* ch = new CardHolder();
    state->ch = ch;
    eventHandler->add_interactive(ch);
    eventHandler->add_interactive(b);
    //end temporary
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
        t.x = normalize_position_to_pixels_x(event.tfinger.x);
        t.y = normalize_position_to_pixels_y(event.tfinger.y);
        Interactive* i = eventHandler->get_touched_interactive(t);
        if(i != NULL)
            i->on_touch_down(t);
    }
    if (event.type == SDL_FINGERMOTION ){
        SDL_Point t;
        t.x = normalize_position_to_pixels_x(event.tfinger.x);
        t.y = normalize_position_to_pixels_y(event.tfinger.y);
        Interactive* i = eventHandler->get_touched_interactive(t);
        if(i != NULL)
            i->on_touch_move(t);
    }
    if (event.type == SDL_FINGERUP ){
        SDL_Point t;
        t.x = normalize_position_to_pixels_x(event.tfinger.x);
        t.y = normalize_position_to_pixels_y(event.tfinger.y);
        Interactive* i = eventHandler->get_touched_interactive(t);
        if(i != NULL)
            i->on_touch_up(t);

    }
}