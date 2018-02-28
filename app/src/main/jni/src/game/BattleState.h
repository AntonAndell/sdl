//
// Created by alex on 2/14/2018.
//

#ifndef SDL_BATTLESTATE_H
#define SDL_BATTLESTATE_H


#include "../../SDL2/include/SDL_events.h"
#include "../game_objects/ui/Button.h"
#include "../game_objects/cards/CardHolder.h"
#include "GameState.h"
#include "EventHandler.h"

class BattleState : public GameState {
public:
    BattleState();

    SDL_Texture* image;
    void update();
    void draw( );
    void handleEvent(SDL_Event event);

private:
    EventHandler* eventHandler;
    CardHolder* ch;
    Button* end_turn_button;
};


#endif //SDL_BattleSTATE_H
