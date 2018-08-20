#ifndef KARTE_HPP
#define KARTE_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <vector>
#include "SDL2/SDL.h"
#include <unordered_map>

class game;

class karte{
public:
    karte(void){}
    karte(game* spiel, const char* path);

    void draw();

    void changecxcy(double x, double y);

    uint8_t getCollisionValue(int x, int y);

    double cx, cy;

    int width = 20, hight = 20;

    std::unordered_map<int, std::string> transportMap;

    std::string mapID;
private:
    game* spiel;

    std::vector<std::vector<int>> tiles;

    std::vector<std::vector<uint8_t>> collision;

    SDL_Rect rect = {0,0,0,0};

};

#endif
