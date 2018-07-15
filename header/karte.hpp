#ifndef KARTE_HPP
#define KARTE_HPP

#include "./rpg_definitions.hpp"
#include <vector>
#include "../src/tiles.cpp"

class karte{
public:
        karte(const char* path,  SDL_Renderer* renner);
        SDL_Renderer *renner;
        std::vector<std::vector<tile>> field;
        void draw(int cx,  int cy);
        int mapWidth,  mapHight,  spx,  spy;
};

#endif
