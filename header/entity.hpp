#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <SDL2/SDL.h>

class game;

class entity{
public:
    entity(game* spiel, std::string kindOfTexture);
    entity(void){}
protected:
    SDL_Rect rectangle;
    game* spiel;
    std::string kindOfTexture;
};

#endif
