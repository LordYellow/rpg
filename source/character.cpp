#include "./../header/character.hpp"
#include "./../header/game.hpp"

character::character(game* spiel, std::string kindOfTexture, int x, int y): entity(spiel, kindOfTexture, x, y) {
    
}

void character::draw(){
    this->update();
    if(round(this->animation) >= 4) this->animation = 0;
    this->spiel->texture.renderTexture(this->direction*4 + (round(this->animation)), this->kindOfTexture, this->rectangle, this->rectangle.h, this->rectangle.w);
}

void character::update(){
    this->rectangle.x = this->x + this->spiel->map.cx;
    this->rectangle.y = this->y + this->spiel->map.cy;
}
