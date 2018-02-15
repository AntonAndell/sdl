//
// Created by alex on 2/14/2018.
//

#include "GameState.h"
#include "../../SDL2/src/render/SDL_sysrender.h"


GameState::GameState(){
    x = y = 0;
}

void GameState::update(){
    x += 0.03;
    y += 0.05;
}
void GameState::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(renderer);
    SDL_Rect fillRect = { (int)x, (int)y, 70, 70};
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect( renderer, &fillRect );
    SDL_RenderPresent(renderer);
}
void GameState::handleEvent(SDL_Event event){

}