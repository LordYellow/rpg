#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <SDL2/SDL.h>

class game;

class entity{
public:
    entity(game* spiel, std::string kindOfTexture, int x, int y);
    entity(void){}
    int getX(){return this->rectangle.x;}
    int getY(){return this->rectangle.y;}
protected:
    SDL_Rect rectangle;
    game* spiel;
    std::string kindOfTexture;
    int x, y;
};

#endif
