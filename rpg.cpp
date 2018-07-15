#include "./header/rpg_definitions.hpp"
#include "./src/karte.cpp"
#include "./header/events.hpp"
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
        
        karte k("maps/test", renner);
        
        SDL_SetEventFilter(filter, NULL);
        
        int cx = 0, cy = 0;
        
        for(;running;){
                SDL_SetRenderDrawColor(renner, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renner);
                
                events(&event, &cx, &cy);
                
                k.draw(cx, cy);
                DEB_MSG_3("cx: " + _T(cx))
                DEB_MSG_3("cy: " + _T(cy))
                
                SDL_RenderPresent(renner);
        }

        
        
        
        SDL_DestroyRenderer(renner);
        SDL_DestroyWindow(win);
        SDL_Quit();
}
