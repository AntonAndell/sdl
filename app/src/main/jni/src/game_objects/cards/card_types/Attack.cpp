//
// Created by anton on 2018-02-13.
//

#include "Attack.h"
#include "../../../../SDL2_image/SDL_image.h"

SDL_Texture *Attack::get_image(SDL_Renderer* r) {
    return IMG_LoadTexture(r, "game_objects/cards/attack.png");
}

Attack::Attack() {

}




