


#include "SDL.h"
int normalize_position_to_pixels_x(double);
int normalize_position_to_pixels_y(double);
double normalize_position_from_pixels_x(int);
double normalize_position_from_pixels_y(int);
SDL_Rect get_screen_size();
bool contains(SDL_Rect* frame, SDL_Point touchLocation);
