

#include "../../SDL2/include/SDL_rect.h"

SDL_Point normalize_position_to_pixels(SDL_Point touchLocation, SDL_Rect screen);
SDL_Point normalize_position_from_pixels(SDL_Point touchLocation, SDL_Rect screen);
bool contains(SDL_Rect* frame, SDL_Point touchLocation);
