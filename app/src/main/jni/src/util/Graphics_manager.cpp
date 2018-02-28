//
// Created by anton on 2018-02-23.
//

#include <SDL_image.h>
#include <assert.h>
#include "Graphics_manager.h"
#include "../../SDL2/include/SDL_render.h"
#include "../../SDL2_image/SDL_image.h"

void render(SDL_Texture* texture, SDL_Rect rect){
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}
void render_ex(SDL_Texture* texture, SDL_Rect rect, int angle ){
    SDL_RenderCopyEx(renderer, texture, NULL, &rect,angle,NULL,SDL_FLIP_NONE);
}

SDL_Texture *get_texture_from_path(const char* path) {
    return IMG_LoadTexture(renderer, path);
}

