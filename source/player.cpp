#ifndef PLAYER_CPP
#define Player_CPP

#include "./../header/player.hpp"
#include <math.h>

player::player(texture* tx, karte* map, std::map<int, int>* eventmap){
    this->textures = tx;
    this->map = map;
    this->eventmap = eventmap;
}

void player::move(int x, int y){
    if(true){
        if(x == 0){
            if(y > 0){
                this->direction = 0;
            }else{
                this->direction = 3;
            }
            if(this->rectangle.y+y < 2*(HIGHT) || this->rectangle.y+y > SCREENHIGHT+2*(-HIGHT)-48){
                this->map->changecxcy(PICSIZE/16*x,PICSIZE/16*y);
            }else if(this->rectangle.y+y < 6*(HIGHT) || this->rectangle.y+y > SCREENHIGHT+6*(-HIGHT)-48){
                if(this->rectangle.y+y < 6*(HIGHT)){
                    this->rectangle.y+=(y*PICSIZE/16); //placeholder for later
                }else{
                    this->rectangle.y+=(y*PICSIZE/16); //placeholder for later
                }
            }else{
                this->rectangle.y+=(y*PICSIZE/16);
            }
        }else{
            if(x > 0){
                this->direction = 2;
            }else{
                this->direction = 1;
            }
            if(this->rectangle.x+x < 2*(WIDTH) || this->rectangle.x+x > SCREENWIDTH+2*(-WIDTH)-48){
                this->map->changecxcy(PICSIZE/16*x,PICSIZE/16*y);
            }else if(this->rectangle.x+x < 6*(WIDTH) || this->rectangle.x+x > SCREENWIDTH+6*(-WIDTH)-48){
                if(this->rectangle.x+x < 6*WIDTH){
                    this->rectangle.x+=(x*PICSIZE/16); //placeholder for later
                }else{
                    this->rectangle.x+=(x*PICSIZE/16); //placeholder for later
                }
            }else{
                this->rectangle.x+=(x*PICSIZE/16);
            }
        }
        this->animation+=0.1;
    }
}

void player::draw(){
    DEB_MSG_3(_T(this->direction*4) + " + " + _T(this->animation))
    if(round(this->animation) >= 4) this->animation = 0;
    this->textures->renderTexture(this->direction*4 + (round(this->animation)), 1, this->rectangle, 48, 32);
}

#endif
