#ifndef PLAYER_CPP
#define Player_CPP

#include "./../header/player.hpp"
#include <math.h>

player::player(texture* tx, karte* map, std::map<int, int>* eventmap, config* configuration){
    this->textures = tx;
    this->map = map;
    this->eventmap = eventmap;
    this->configuration = configuration;
    this->interface = ui(this->configuration, this->textures);
}

void player::move(int x, int y){
    STARTTEST
    if(this->walkable(x, y)){
        if(x == 0){
            this->direction = ((y>0)?0:3);
            if(this->rectangle.y+y < 2*(HIGHT) || this->rectangle.y+y > SCREENHIGHT+2*(-HIGHT)-48){
                this->map->changecxcy(SPEED*x,SPEED*y);
            }else if(this->rectangle.y+y < 6*(HIGHT) || this->rectangle.y+y > SCREENHIGHT+6*(-HIGHT)-48){
                if(this->rectangle.y+y < 6*(HIGHT)){
                    this->rectangle.y+=(y*SPEED); //placeholder for later
                }else{
                    this->rectangle.y+=(y*SPEED); //placeholder for later
                }
            }else{
                this->rectangle.y+=(y*SPEED);
            }
        }else{
            this->direction = ((x>0)?2:1);
            if(this->rectangle.x+x < 2*(WIDTH) || this->rectangle.x+x > SCREENWIDTH+2*(-WIDTH)-48){
                this->map->changecxcy(SPEED*x,SPEED*y);
            }else if(this->rectangle.x+x < 6*(WIDTH) || this->rectangle.x+x > SCREENWIDTH+6*(-WIDTH)-48){
                if(this->rectangle.x+x < 6*WIDTH){
                    this->rectangle.x+=(x*SPEED); //placeholder for later
                }else{
                    this->rectangle.x+=(x*SPEED); //placeholder for later
                }
            }else{
                this->rectangle.x+=(x*SPEED);
            }
        }
    }
    this->animation+=0.1;
    STOPTEST("testmove")
}

void player::draw(){
    this->interface.draw(this->life, this->ausdauer, this->gold, this->experience);
    DEB_MSG_3(_T(this->direction*4) + " + " + _T(this->animation))
    if(round(this->animation) >= 4) this->animation = 0;
    this->textures->renderTexture(this->direction*4 + (round(this->animation)), 1, this->rectangle, 48, 32);
}

bool player::walkable(int x, int y){
    uint8_t ptw = this->map->getCollisionValue((rectangle.x + x*PICSIZE/16 + 16), (rectangle.y + y*PICSIZE/16 + 32));
    
    return !ptw; //placeholder
}

#endif
