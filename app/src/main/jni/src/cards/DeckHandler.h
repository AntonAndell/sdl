//
// Created by anton on 2018-02-13.
//
#include <vector>
#include "Card.h"
using namespace std;

#ifndef SDL_DECKHANDLER_H
#define SDL_DECKHANDLER_H


class DeckHandler {
    vector<Card> draw_pile;
    vector<Card> discard_pile;
public:
    Card get_next();
    void shuffle();
    int get_cards_left();
    int get_discarded_cards();
    void discard(Card card);

private:

};


#endif //SDL_DECKHANDLER_H
