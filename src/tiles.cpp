#ifndef TILES_CPP
#define TILES_CPP

#include "./../header/rpg_definitions.hpp"
#include "./../header/tiles.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#define SCOPE_NAME tiles
#include "./../header/debug.hpp"

using namespace std;

tile::tile(const char* path, SDL_Renderer* renner){
    this->path = path;
    if((this->notwalkable())){this->walkable = false;}else{this->walkable = true;}
    this->renner = renner;
    this->image = IMG_Load(path);
    DEB_MSG_3(IMG_GetError())
    this->texture = SDL_CreateTextureFromSurface(this->renner, this->image);
}

void tile::draw(int x, int y){
    this->dst.x=x;
    this->dst.y=y;
    SDL_QueryTexture(this->texture, NULL, NULL, &this->dst.w, &this->dst.h);
    SDL_RenderCopy(renner, this->texture, NULL, &this->dst);
}

bool tile::notwalkable(){
    string pathstring = this->path;
    pathstring.erase(pathstring.begin(), pathstring.begin()+19);
    
    if(pathstring == "dont") return true;
    
    return false;
}

#undef SCOPE_NAME
#endif
