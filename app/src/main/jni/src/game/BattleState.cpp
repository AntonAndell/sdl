//
// Created by alex on 2/14/2018.
//

#include "BattleState.h"
#include "../../SDL2/src/render/SDL_sysrender.h"
#include "../../SDL2/include/SDL_log.h"


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
void BattleState::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(renderer);
    //render cardhodler
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0xFF, 0xFF );

    SDL_RenderDrawRect(renderer, ch->get_frame());
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0xFF, 0xFF );
    SDL_RenderFillRect(renderer, end_turn_button->get_frame());
    ch->draw(renderer);
    SDL_RenderPresent(renderer);
}

void BattleState::handleEvent(SDL_Event event){
    SDL_Point t;
    if (event.type == SDL_FINGERDOWN || event.type == SDL_FINGERMOTION ||event.type == SDL_FINGERUP)

        t.x = normalize_position_to_pixels_x(event.tfinger.x);
        t.y = normalize_position_to_pixels_y(event.tfinger.y);
        Interactive* i = eventHandler->get_touched_interactive(t);
        if(i != NULL){
            switch (event.type){
                case SDL_FINGERDOWN:
                    //check if the interactive want to lock
                    if(i->on_touch_down(t))
                        eventHandler->lock(i);
                    break;
                case SDL_FINGERUP:
                    i->on_touch_up(t);
                    eventHandler->unlock();
                    break;
                case SDL_FINGERMOTION:
                    i->on_touch_move(t);

                    break;
                default:
                    break;
            }
        }


}

