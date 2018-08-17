#ifndef GAME_HPP
#define GAME_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <vector>
#include "./karte.hpp"
#include "./config.hpp"
#include "./textureloader.hpp"
#include "./player.hpp"
#include "./npc.hpp"

class game{
public:
    game(void);
    ~game(void);
    
    int getStateOfGame(){return this->stateOfGame;}
    
    void update();
    
    void handleEvents();
    
    void load(const char* path);
    
public:
    int stateOfGame = RUNNING;
    SDL_Window *win;
    SDL_Renderer *renner;
    SDL_Event event;
    std::map<int, int> keys;
    textureloader texture;
    karte map;
    player spieler;
    config configuration;
    std::vector<npc> npcvector;
};

#endif
