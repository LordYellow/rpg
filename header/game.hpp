#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include "./texture.hpp"
#include "./karte.hpp"
#include "./player.hpp"

class game{
public:
    game();
    
    int running = 1;
    void run();
    void stop();
    void handleEvents();
    void load(const char* path);
private:
    SDL_Window *win;
    SDL_Renderer *renner;
    SDL_Event event;
    std::map<int, int> keys;
    texture textureloader;
    karte currentmap;
    player spieler;
    
    //event Stuff
    int filter();
    void onQuit();
    void onKeyDown();
    void onKeyUp();
    
};

#endif
