#ifndef UI_HPP
#define UI_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include "./texture.hpp"
#include "./config.hpp"


class ui{
public:
    ui(config* configuration, texture* textures);
    ui(){}
    
    void draw(double life, double ausdauer, double gold, double experience);
private:
    
    SDL_Color color = {0,0,0,0};
    
    SDL_Rect rectangle = {0,0,232,78};
    SDL_Rect barrect = {0,0,100,6};
    SDL_Rect goldrect = {0,0,32,32};
    
    config *configuration;
    texture *textures;
};

#endif
