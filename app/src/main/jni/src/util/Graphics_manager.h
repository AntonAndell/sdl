//
// Created by anton on 2018-02-23.
//

#ifndef SDL_GRAPHICS_MANAGER_H
#define SDL_GRAPHICS_MANAGER_H

#include "../../SDL2/src/render/SDL_sysrender.h"
#include "../../SDL2/include/SDL_rect.h"
#include <string>

extern SDL_Renderer* renderer;

void render_ex(SDL_Texture* texture, SDL_Rect rect, int angle );
void render(SDL_Texture* texture, SDL_Rect rect);
SDL_Texture* get_texture_from_path(const char* path);

#endif //SDL_GRAPHICS_MANAGER_H
