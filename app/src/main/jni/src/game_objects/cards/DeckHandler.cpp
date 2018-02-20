//
// Created by anton on 2018-02-13.
//

#include "DeckHandler.h"
#include "card_types/Attack.h"

Card* DeckHandler::get_next() {
    Attack* a = new Attack();
    return a;
}


