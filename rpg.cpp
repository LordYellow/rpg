#include "./header/rpg_definitions.hpp"
#include "./src/karte.cpp"
#include "./header/events.hpp"
#include "./src/player.cpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

int main(){
        if(SDL_Init(SDL_INIT_VIDEO) != 0){std::cout << "error: " << SDL_GetError() << std::endl; return 1;}
        SDL_Window *win = SDL_CreateWindow("Titel",100,200,WIDTH,HIGHT,SDL_WINDOW_SHOWN);
        if(win == nullptr){std::cout << "winerror: " << SDL_GetError() << std::endl; SDL_Quit(); return 1;}
        SDL_Renderer *renner = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(renner == nullptr){SDL_DestroyWindow(win); std::cout << "renderererror: " << SDL_GetError() << std::endl; SDL_Quit(); return 1;}
        SDL_Event event;
        karte k("maps/map", renner);
        player you("./images/player/", 44*16, 25*16, renner, &k);
        
        SDL_SetEventFilter(filter, NULL);
        
        int cx = 0, cy = 0;
        
        for(;running;){
                SDL_SetRenderDrawColor(renner, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renner);
                
                events(&event, &cx, &cy, &you);
                
                k.draw(cx, cy);
                
                you.draw();
                
                k.drawobstacle(cx, cy);
                
                SDL_RenderPresent(renner);
        }

        
        
        
        SDL_DestroyRenderer(renner);
        SDL_DestroyWindow(win);
        SDL_Quit();
}
