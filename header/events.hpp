#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SDL2/SDL.h>
#include <map>

using namespace std;

uint8_t running = 1;
map<int, int> keys;

int filter(void* argumente, SDL_Event* event){
  return !(event->type == SDL_MOUSEMOTION);
}

void onQuit(){
  running = 0;
}

void onKeyDown(SDL_Event* event){
  keys[event->key.keysym.sym] = 1;
}

void onKeyUp(SDL_Event* event){
  keys[event->key.keysym.sym] = 0;
}

void events(SDL_Event* event, int* cx, int* cy){
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
        
        if(keys[SDLK_w]){(*cy)++;}
        if(keys[SDLK_s]){(*cy)--;}
        if(keys[SDLK_a]){(*cx)++;}
        if(keys[SDLK_d]){(*cx)--;}
}

#endif
