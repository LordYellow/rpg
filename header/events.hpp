#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SDL2/SDL.h>
#include <map>
#include "./../src/player.cpp"

using namespace std;

uint8_t running = 1;
map<int, int> keys;

/**
 * @brief filter for events. Does not count Moues motion as event
 * 
 * @param event is the SDL event thing
 * 
 * @return does not matter sdl handels this
 */
int filter(void* argumente, SDL_Event* event){
  return !(event->type == SDL_MOUSEMOTION);
}

/**
 * @brief quits the game
 */
void onQuit(){
  running = 0;
}

/**
 * @brief used for user input
 */
void onKeyDown(SDL_Event* event){
  keys[event->key.keysym.sym] = 1;
}

/**
 * @brief used for user input 
 */
void onKeyUp(SDL_Event* event){
  keys[event->key.keysym.sym] = 0;
}

/**
 * @brief handels the event stuff for sdl
 */
void events(SDL_Event* event, int* cx, int* cy, player *you){
        if(SDL_PollEvent(event)){
                switch ((*event).type) {
                        case SDL_QUIT: onQuit(); break;
                        case SDL_KEYDOWN: onKeyDown(event); break;
                        case SDL_KEYUP: onKeyUp(event); break;
                        case SDL_MOUSEBUTTONDOWN: break;
                        case SDL_MOUSEBUTTONUP: break;
                        case SDL_MOUSEMOTION: break;
                }
        }
        
        if(keys[SDLK_w]){(*you).move(0,-1);}
        if(keys[SDLK_s]){(*you).move(0,1);}
        if(keys[SDLK_a]){(*you).move(-1,0);}
        if(keys[SDLK_d]){(*you).move(1,0);}
        
        //SDL_FlushEvent(SDL_KEYDOWN);
}

#endif
