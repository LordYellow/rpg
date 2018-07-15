#ifndef KARTE_HPP
#define KARTE_HPP

#include "./rpg_definitions.hpp"
#include <vector>
#include <map>
#include "../src/tiles.cpp"

class karte{
public:
        karte(const char* path,  SDL_Renderer* renner);
        SDL_Renderer *renner;
        
        //in this "map" every tile is stored. only the neede tiles will be drawn
        std::vector<std::vector<tile>> field;
        
        /**
         * @brief draws the needed tiles
         * 
         * @param cx is used to change the part you see (x direction)
         * @param cy is used to change the part you see (y direction)
         */
        void draw(int cx,  int cy);
        
        // needed to draw the map in the center of the screen
        int mapWidth,  mapHight,  spx,  spy;
};

#endif
