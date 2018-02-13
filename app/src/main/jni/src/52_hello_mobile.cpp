#include "SDL.h"
#include "SDL_image.h"
#include "../SDL2_image/SDL_image.h"

/* XPM */
static char * icon_xpm[] = {
        "32 23 3 1",
        "     c #FFFFFF",
        ".    c #000000",
        "+    c #FFFF00",
        "                                ",
        "            ........            ",
        "          ..++++++++..          ",
        "         .++++++++++++.         ",
        "        .++++++++++++++.        ",
        "       .++++++++++++++++.       ",
        "      .++++++++++++++++++.      ",
        "      .+++....++++....+++.      ",
        "     .++++.. .++++.. .++++.     ",
        "     .++++....++++....++++.     ",
        "     .++++++++++++++++++++.     ",
        "     .++++++++++++++++++++.     ",
        "     .+++++++++..+++++++++.     ",
        "     .+++++++++..+++++++++.     ",
        "     .++++++++++++++++++++.     ",
        "      .++++++++++++++++++.      ",
        "      .++...++++++++...++.      ",
        "       .++............++.       ",
        "        .++..........++.        ",
        "         .+++......+++.         ",
        "          ..++++++++..          ",
        "            ........            ",
        "                                "};

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect screenRect;
    int done;
    SDL_Event event;

    //init subsystem
    SDL_VideoInit(NULL);
    //get display size
    SDL_DisplayMode displayMode;
    if( SDL_GetCurrentDisplayMode( 0, &displayMode ) == 0 ) {
        screenRect.w = displayMode.w;
        screenRect.h = displayMode.h;
    }else{
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());

    }

    if (SDL_CreateWindowAndRenderer(screenRect.w, screenRect.h, 0, &window, &renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "SDL_CreateWindowAndRenderer() failed: %s", SDL_GetError());
        return(2);
    }

    surface = IMG_ReadXPMFromArray(icon_xpm);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't load texture: %s", SDL_GetError());
        return(2);
    }

    done = 0;
    SDL_Point touchLocation = { screenRect.w / 2, screenRect.h / 2 };
    while (!done) {
        SDL_RenderCopy(renderer, texture, NULL, NULL);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                done = 1;
            if (event.type == SDL_FINGERDOWN ){
                touchLocation.x = event.tfinger.x * screenRect.w;
                touchLocation.y = event.tfinger.y * screenRect.h;
                SDL_Log("%d %d", screenRect.w,screenRect.h);
                SDL_Log("%d %d", event.tfinger.x * screenRect.w, event.tfinger.y * screenRect.h);

            }

        }

        SDL_Rect fillRect = { touchLocation.x-40, touchLocation.y-40, 80, 80};
        SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect( renderer, &fillRect );
        SDL_RenderPresent(renderer);


    }
    SDL_DestroyTexture(texture);

    SDL_Quit();
    return(0);
}
