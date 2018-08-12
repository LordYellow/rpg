#ifndef KARTE_HPP
#define KARTE_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <vector>
#include "SDL2/SDL.h"

class game;

class karte{
public:
    karte(void){}
    karte(game* spiel, const char* path);
    
    void draw();
    
    void changecxcy(double x, double y);
    
    uint8_t getCollisionValue(int x, int y);
    
    double cx, cy;
    
private:
    game* spiel;
    
    std::vector<std::vector<int>> tiles;
    
    std::vector<std::vector<uint8_t>> collision;
    
    int width = 20, hight = 20;
    
    SDL_Rect rect = {0,0,0,0};
};

#endif
