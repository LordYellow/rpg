#ifndef PLAYER_HPP
#define PLATER_HPP

#include "./rpg_definitions.hpp"
#include "./../src/karte.cpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class player{
public:
    player(string path, int x, int y,  SDL_Renderer* renner, karte* map);
    string path;
    int pos = 0;
    bool running = false;
    SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
    bool flipit = false;
    karte *map;
    
    SDL_Surface *image; 
    SDL_Texture *texture;
    SDL_Renderer *renner;
    SDL_Rect dst;
    
    void draw();
    bool walkable(int x, int y);
    void move(int x, int y);
};

#endif
