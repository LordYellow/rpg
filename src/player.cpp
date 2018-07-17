#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "./../header/player.hpp"
#include <math.h>

using namespace std;

player::player(string path, int x, int y,  SDL_Renderer* renner, karte* map){
    this->renner = renner;
    this->path = path;
    this->dst.x = x;
    this->dst.y = y;
    this->map = map;
}

void player::draw(){
    if((this->running)){running = false;}else{this->pos = 0;}
    string realpath = path + "run" + to_string(((this->pos+1)/(PICSIZE/2)) %7) + ".png";
    this->image = IMG_Load(realpath.c_str());
    DEB_MSG_3(IMG_GetError())
    this->texture = SDL_CreateTextureFromSurface(this->renner, this->image);
    SDL_QueryTexture(this->texture, NULL, NULL, &this->dst.w, &this->dst.h);
    DEB_MSG_3("Player Width: " + _T(this->dst.w) + " Hight: " + _T(this->dst.h))
    if(this->flipit){SDL_RenderCopyEx(renner, this->texture, NULL, &this->dst, 0, NULL, this->flip);}else{SDL_RenderCopy((renner), this->texture, NULL, &this->dst);}
}

bool player::walkable(int x, int y){
    DEB_MSG_3(" x: " + _T(this->dst.x + x) + " y: " + _T(this->dst.y + y))
    //return true;
    return ((this->map->walkable[this->dst.y+8 + y][this->dst.x + x+2]) && (this->map->walkable[this->dst.y+23 + y][this->dst.x + x+2]) && (this->map->walkable[this->dst.y + y+8][this->dst.x+15 + x]) && (this->map->walkable[this->dst.y+23 + y][this->dst.x+15 + x]));
}

void player::move(int x, int y){
    if(this->walkable(x, y)){
        if(x == 0){
            this->dst.y+=(PICSIZE/8)*y; 
            this->pos++;
            this->running = true;
        }else{
            this->dst.x+=(PICSIZE/8)*x;
            this->pos++;
            this->running = true;
            flipit = (x < 0);
        }
    }
}

#endif
