#ifndef GAME_CPP
#define GAME_CPP

#include "./../header/game.hpp"
#include "./../header/rpg_definitions.hpp"
#include "./../header/debug.hpp"

//do not use the namespace std!

game::game(){
    //SDL init stuff
    if(SDL_Init(SDL_INIT_VIDEO) != 0){std::cout << "error: " << SDL_GetError() << std::endl; return;}
    this->win = SDL_CreateWindow("Titel",100,200,SCREENWIDTH,SCREENHIGHT,SDL_WINDOW_SHOWN);
    if(win == nullptr){std::cout << "winerror: " << SDL_GetError() << std::endl; SDL_Quit(); return;}
    this->renner = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renner == nullptr){SDL_DestroyWindow(this->win); std::cout << "renderererror: " << SDL_GetError() << std::endl; SDL_Quit(); return;}
}

void game::run(){
    DEB_MSG_3("running")
    
    //clears anything
    SDL_SetRenderDrawColor(this->renner, 0,0,0,0);
    SDL_RenderClear(this->renner);
    
    //this draws the map
    this->currentmap.draw();
    
    //this draws the player
    this->spieler.draw();

    SDL_RenderPresent(this->renner);
    SDL_Delay(1);
}

void game::stop(){
    //ends the sdl stuff. i think i could write this into the destructor, but tbh im not entirely sure how a destructor works
    SDL_DestroyRenderer(this->renner);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
}

void game::load(const char* path){
    
    //loads the textureloader
    this->textureloader = texture(this->renner);
    
    //this loads the map at the given path
    this->currentmap = karte(path, &textureloader);
    
    //this  loads the player
    this->spieler = player(&this->textureloader, &this->currentmap, &this->keys);
}

void game::handleEvents(){
    //looks for events
    if(SDL_PollEvent(&this->event)){
        switch(this->event.type){
            case SDL_QUIT: this->onQuit(); break;
            case SDL_KEYDOWN: this->onKeyDown(); break;
            case SDL_KEYUP: this->onKeyUp(); break;
        }
    }
    
    //wasd commands the palyer to move
    if(keys[SDLK_w]){(this->spieler).move(0,-1);}
    if(keys[SDLK_s]){(this->spieler).move(0,1);}
    if(keys[SDLK_a]){(this->spieler).move(-1,0);}
    if(keys[SDLK_d]){(this->spieler).move(1,0);}
    
}

void game::onQuit(){
    this->running = 0;
}

void game::onKeyDown(){
    this->keys[this->event.key.keysym.sym] = 1;
}

void game::onKeyUp(){
    this->keys[this->event.key.keysym.sym] = 0;
}

#endif
