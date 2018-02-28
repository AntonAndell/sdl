//
// Created by alex on 2/14/2018.
//

#include "BattleState.h"
#include "../../SDL2/src/render/SDL_sysrender.h"
#include "../../SDL2/include/SDL_log.h"
#include "../util/Graphics_manager.h"


BattleState::BattleState(){

    eventHandler = new EventHandler();
    end_turn_button = new Button();
    ch = new CardHolder();
    eventHandler->add_interactive(ch);
    eventHandler->add_interactive(end_turn_button);

}

void BattleState::update(){
    if(end_turn_button->end_turn()){
        end_turn_button->reset();
        ch->next_turn();
        SDL_Log("ended turnenenen");
    }
}
void BattleState::draw(){
    SDL_Log("1_______-----");

    SDL_Log("2_______-----");
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_Log("3_______-----");
    SDL_RenderClear(renderer);
    //render cardhodler
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF );
    SDL_Log("2_______-----");
    SDL_RenderDrawRect(renderer, ch->get_frame());
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0xFF, 0xFF );
    SDL_RenderFillRect(renderer, end_turn_button->get_frame());
    ch->draw();
    SDL_RenderPresent(renderer);
    SDL_Log("3_______-----");
}

void BattleState::handleEvent(SDL_Event event){
   eventHandler->handle_touch(event);
}

