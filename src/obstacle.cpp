#ifndef OBSTACLE_CPP
#define OBSTACLE_CPP

#include "./../header/rpg_definitions.hpp"
#include "./../header/obstacle.hpp"

obstacle::obstacle(const char* path, SDL_Renderer* renner, int x, int y){
    string realpath = "./images/obstacles/";
    realpath.append(path);
    this->path = realpath.c_str();
    if((this->notwalkable())){this->walkable = false;}else{this->walkable = true;}
    this->renner = renner;
    this->image = IMG_Load(realpath.c_str());
    DEB_MSG_3(IMG_GetError())
    this->texture = SDL_CreateTextureFromSurface(this->renner, this->image);
    this->dst.x=x*PICSIZE;
    this->dst.y=y*PICSIZE;
}

void obstacle::draw(int x, int y){
    this->dst.x+=(x*PICSIZE);
    this->dst.y+=(y*PICSIZE);
    SDL_QueryTexture(this->texture, NULL, NULL, &this->dst.w, &this->dst.h);
    SDL_RenderCopy(renner, this->texture, NULL, &this->dst);
    this->dst.x-=(x*PICSIZE);
    this->dst.y-=(y*PICSIZE);
}

#endif
