#ifndef KARTE_HPP
#define KARTE_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include "./texture.hpp"
#include <vector>

class karte{
public:
    karte(const char* path, texture* txp);
    karte(){}
    
    void draw();
    void changecxcy(double x, double y);
private:
    std::vector<std::vector<int>> tiles;
    texture *textures;
    int width, hight;
    double cx, cy;
    SDL_Rect rect = {0,0,PICSIZE, PICSIZE};
};

#endif
