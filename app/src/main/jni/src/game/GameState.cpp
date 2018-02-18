//
// Created by alex on 2/14/2018.
//

#include "GameState.h"
#include "../../SDL2/src/render/SDL_sysrender.h"


GameState::GameState(){
}

void GameState::update(){

}
void GameState::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
}
void GameState::handleEvent(SDL_Event event){

}