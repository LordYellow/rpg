#include "./../header/player.hpp"
#include "./../header/game.hpp"

player::player(game* spiel, std::string kindOfTexture): character(spiel, kindOfTexture){
    this->rectangle.x = std::stoi(this->spiel->configuration["screenwidth"])/2-std::stoi(this->spiel->configuration["playerWidth"])/2;
    this->rectangle.y = std::stoi(this->spiel->configuration["screenhight"])/2-std::stoi(this->spiel->configuration["playerHight"])/2;
    this->rectangle.w = std::stoi(this->spiel->configuration["playerWidth"]);
    this->rectangle.h = std::stoi(this->spiel->configuration["playerHight"]);
}

void player::move(){
    //this actually is the test if i can overwrite it like i wanted to. i was succesfull, but for obvious reasons i dont need that in the player class
}

void player::doMove(int x, int y){
    if(this->walkable(x, y)){
        if(x == 0){
            this->direction = ((y>0)?0:3);
        }else{
            this->direction = ((x>0)?2:1);
        }
        this->spiel->map.changecxcy(x*std::stoi(this->spiel->configuration["speed"]), y*std::stoi(this->spiel->configuration["speed"]));
    }
    this->animation+=0.1;
}

bool player::walkable(int x, int y){
    return true; //placeholder
}
