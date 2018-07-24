#ifndef ENEMY_CPP
#define ENEMY_CPP

#include "./../header/enemy.hpp"

enemy::enemy(int posX, int posY, uint8_t direction, std::string name, int kindofTexture, texture* textures){
    this->moving = false;
    
    this->textures = textures;
    this->direction = direction;
    this->name = name;
    this->kindofTexture = kindofTexture;
    this->rectangle.x = posX;
    this->rectangle.y = posY;
    
    this->lifebar.x = posX - 9;
    this->lifebar.y = posY - 7;
}

enemy::enemy(int posX, int posY, uint8_t direction, std::string name, int kindofTexture, int targetX, int targetY, int speed, texture* textures){
    this->moving = true;
    
    this->textures = textures;
    this->direction = direction;
    this->name = name;
    this->kindofTexture = kindofTexture;
    this->speed = speed;
    this->rectangle.x = posX;
    this->rectangle.y = posY;
    if(posX > targetX){this->posX = targetX; this->targetX = posX;}else{this->posX = posX; this->targetX = targetX;}
    if(posX > targetY){this->posY = targetY; this->targetY = posY;}else{this->posY = posY; this->targetY = targetY;}
    
    if((targetX - posX)){
        if(targetX < posX){
            this->cx = 1;
        }else{
            this->cx = -1;
        }
    }else{
        if(targetY < posY){
            this->cy = 1;
        }else{
            this->cy = -1;
        }
    }
}

void enemy::update(){
    if(this->moving){
        this->move();
        if(round(this->animation) >= 4) this->animation = 0;
        this->lifebar.y = this->rectangle.y - 7;
        this->lifebar.x = this->rectangle.x - 9;
    }
    this->textures->renderTexture(this->direction*4 + (round(this->animation))+16*this->kindofTexture, 1, this->rectangle, 48, 32);
    
    this->color.r = 200;
    this->color.g = 200;
    this->color.b = 200;
    this->lifebar.w = 50;
    this->textures->drawRectangle(this->lifebar, this->color, true);
    
    this->color.b = 0;
    this->lifebar.w = this->life/2;
    if(this->life > 50){
        this->color.r = 255-2.55*2*this->life;
        this->color.g = 255;
    }else{
        this->color.r = 255;
        this->color.g = 2.55*2*this->life;
    }
    this->textures->drawRectangle(this->lifebar, this->color, true);
    
    this->lifebar.w = 50;
    this->color.r = 0;
    this->color.g = 0;
    this->textures->drawRectangle(this->lifebar, this->color, false);
    
    this->lifebar.x+=(9+16-(name.length()*6)/2);
    this->lifebar.y-= 12;
    this->textures->writeText(this->name, this->lifebar, 12, this->color);
    this->lifebar.x-=(9+16-(name.length()*6)/2);
    this->lifebar.y+= 12;
}

void enemy::move(){ //lets call it a placeholder
    this->animation+=0.1;
    this->rectangle.x+=(this->cx*this->speed);
    this->rectangle.y+=(this->cy*this->speed);
    if(this->rectangle.y > this->targetY  || this->rectangle.y < this->posY){this->cy*=-1; if(this->direction == 3){this->direction = 0;}else{this->direction = 3;}}
    if(this->rectangle.x > this->targetX  || this->rectangle.x < this->posX){this->cx*=-1; if(this->direction == 2){this->direction = 1;}else{this->direction = 2;}}
}
#endif
