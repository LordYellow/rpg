#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include "./texture.hpp"
#include "./karte.hpp"
#include <map>

class player{
public:
    player(texture* tx, karte* map, std::map<int, int>* eventmap);
    player(){}
    
    void draw();
    void move(int x, int y);
private:
    texture *textures;
    karte *map;
    std::map<int, int> *eventmap;
    uint8_t direction = 0;
    double animation = 0;
    SDL_Rect rectangle = {SCREENWIDTH/2,SCREENHIGHT/2,32,48};
};

#endif
