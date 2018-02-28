//
// Created by anton on 2018-02-15.
//

#include <SDL_log.h>
#include "EventHandler.h"

void EventHandler::add_interactive(Interactive* i) {
    objects.push_back(i);
}

EventHandler::EventHandler() {
    locked_interactive = NULL;
}

void EventHandler::lock(Interactive *i) {
    locked_interactive = i;
}
void EventHandler::unlock(){
    locked_interactive = NULL;
}

Interactive *EventHandler::get_locked() {
    return locked_interactive;
}

void EventHandler::handle_touch(SDL_Event event) {
    SDL_Point t;
    t.x = normalize_position_to_pixels_x(event.tfinger.x);
    t.y = normalize_position_to_pixels_y(event.tfinger.y);
    Interactive* i = NULL;
    bool outside = false;
    for(Interactive* i_: objects) {
        if (contains(i_->get_frame(), t)) {
            i = i_;
            break;
        }
    }
    if (i == NULL){
        return;
    }
    if (i == get_locked() && get_locked() != NULL)
        outside = true;
    switch (event.type){
        case SDL_FINGERDOWN:
            //check if the interactive want to lock
            if(i->on_touch_down(t)){
                lock(i);
            }
            break;
        case SDL_FINGERUP:
            if(i->on_touch_up(t, outside))
                unlock();
            break;
        case SDL_FINGERMOTION:
            if(i->on_touch_move(t, outside))
                unlock();
            break;
        default:
            break;
    }
}

