//
// Created by anton on 2018-02-15.
//
#include <vector>
#include "../game_objects/Interactive.h"
#include "../util/TouchUtil.h"

using namespace std;
#ifndef SDL_EVENTHANDLER_H
#define SDL_EVENTHANDLER_H



class EventHandler {
    vector<Interactive*> objects;

public:
    EventHandler();
    void add_interactive(Interactive* i);
    //return null if none is found, touchLocation should be normalized between 0-1
    Interactive* get_touched_interactive(SDL_Point touchLocation);

    void lock(Interactive *);
    void unlock();

    Interactive *get_locked();

private:
    Interactive* locked_interactive;
};


#endif //SDL_EVENTHANDLER_H
