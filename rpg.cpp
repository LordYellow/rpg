#include "./header/rpg_definitions.hpp"
#include "./header/debug.hpp"
#include "./header/game.hpp"

int filter(void* argumente, SDL_Event* event){
    return !(event->type == SDL_MOUSEMOTION );
}

int main(){
    SDL_SetEventFilter(filter, NULL);
    
    game spiel;
    spiel.load("atm this has no purpose");
    
    while(spiel.getStateOfGame()){
        spiel.handleEvents();
        if(spiel.getStateOfGame() == RUNNING || spiel.getStateOfGame() == DIALOG) spiel.update();
    }
}
