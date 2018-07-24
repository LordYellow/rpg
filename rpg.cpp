#include "./header/rpg_definitions.hpp"
#include "./header/debug.hpp"
#include "./header/game.hpp"

int filter(void* argumente, SDL_Event* event){
  return !(event->type == SDL_MOUSEMOTION);
}

int main(){
    STARTTEST
    
    game spiel;
    spiel.load("./maps/testmap");
    
    STOPTEST("test")
    
    SDL_SetEventFilter(filter, NULL);
    
    while(spiel.running){
        spiel.handleEvents();
        if(spiel.running == 1) spiel.run();
    }
    
    spiel.stop();
    
    CLOSETEST
}

