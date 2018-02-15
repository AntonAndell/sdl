//
// Created by anton on 2018-02-15.
//

#include <SDL_log.h>
#include "EventHandler.h"


Interactive* EventHandler::get_touched_interactive(SDL_Point touchLocation){
    for(Interactive* i: objects){
        if (contains(i->get_frame(), touchLocation)) {
            return i;
        }
    }
    return NULL;
}

void EventHandler::add_interactive(Interactive* i) {
    objects.push_back(i);
}
