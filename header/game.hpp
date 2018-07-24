#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include "./texture.hpp"
#include "./karte.hpp"
#include "./player.hpp"
#include "./config.hpp"
#include "./enemy.hpp"

class game{
public:
    game();
    
    //state of the game 0 = Game Over, 1 = running...
    int running = 1;
    
    /**
     * @brief this is the main game loop
     */
    void run();
    
    /**
     * @brief this ends the game
     */
    void stop();
    
    /**
     * @brief handels the events
     */
    void handleEvents();
    
    /**
     * @brief with this you can load a new map to the game
     */
    void load(const char* path);
private:
    
    //the sdl window you use
    SDL_Window *win;
    
    //the sdl rendere you use
    SDL_Renderer *renner;
    
    //the sdl event you use
    SDL_Event event;
    
    //this is a map to know when you press a key
    std::map<int, int> keys;
    
    //this is the "textureloader"
    texture textureloader;
    
    //this is the map you play on
    karte currentmap;
    
    //this is the player
    player spieler;
    
    config configuration;
    
    enemy testgegner;
    
    //event Stuff
    int filter();
    void onQuit();
    void onKeyDown();
    void onKeyUp();
    
};

#endif
