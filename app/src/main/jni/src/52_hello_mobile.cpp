#include "SDL.h"
#include "../SDL2_image/SDL_image.h"
#include "cards/Card.h"

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
int a(){
    SDL_Log("this is me");
    return 1;
}
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
    //creates window and does first render
    if (SDL_CreateWindowAndRenderer(screenRect.w, screenRect.h, 0, &window, &renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "SDL_CreateWindowAndRenderer() failed: %s", SDL_GetError());
        return(2);
    }
    //donno how this stuff works
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
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                done = 1;
            if (event.type == SDL_FINGERDOWN ){
                touchLocation.x = event.tfinger.x * screenRect.w;
                touchLocation.y = event.tfinger.y * screenRect.h;
            }
            if (event.type == SDL_FINGERMOTION ){
                touchLocation.x = event.tfinger.x * screenRect.w;
                touchLocation.y = event.tfinger.y * screenRect.h;
            }
            if (event.type == SDL_FINGERUP ){
                touchLocation.x = screenRect.w / 2;
                touchLocation.y = screenRect.h / 2;
            }

        }

        //clear
        SDL_RenderClear( renderer );

        //GetTexture(State) somthing like this
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_Rect fillRect = { touchLocation.x-10, touchLocation.y-10, 20, 20};
        SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect( renderer, &fillRect );
        SDL_RenderPresent(renderer);


    }
    SDL_DestroyTexture(texture);

    SDL_Quit();
    return(0);
}
