#include "./../header/character.hpp"
#include "./../header/game.hpp"

character::character(game* spiel, std::string kindOfTexture, int x, int y, std::string name, std::string onMap): entity(spiel, kindOfTexture, x, y) {
    this->name = name;
    this->onMap = onMap;

    this->lifeRect.h = 6;
    this->lifeRect.w = 100;
}

void character::draw(){
    if(!(this->onMap == this->spiel->map.mapID || this-> onMap == "PLAYER")) return;
    this->update();
    this->showName();
    if(round(this->animation) >= 4) this->animation = 0;
    this->spiel->texture.renderTexture(this->direction*4 + (round(this->animation)), this->kindOfTexture, this->rectangle, this->rectangle.h, this->rectangle.w);
}

void character::update(){
    this->rectangle.x = this->x + this->spiel->map.cx;
    this->rectangle.y = this->y + this->spiel->map.cy;

    this->lifeRect.x = this->x + this->spiel->map.cx - (50-std::stoi(this->spiel->configuration["playerWidth"]))/2;
    this->lifeRect.y = this->y + this->spiel->map.cy - 10;
}

void character::showName(){
    if(life > 50){
        this->lifecolor.r = 255-2.55*2*this->life;
        this->lifecolor.g = 255;
    }else{
        this->lifecolor.r = 255;
        this->lifecolor.g = 2.55*2*this->life;
    }

    this->lifeRect.w = this->life/2;
    this->spiel->texture.drawRectangle(this->lifeRect, this->lifecolor, true);

    this->lifecolor.b = 0;
    this->lifecolor.r = 0;
    this->lifecolor.g = 0;

    this->lifeRect.w = 100/2;
    this->spiel->texture.drawRectangle(this->lifeRect, this->lifecolor, false);

    this->lifeRect.y-=12;
    this->lifeRect.x = this->x + this->spiel->map.cx - this->name.length()*2.5 + std::stoi(this->spiel->configuration["playerWidth"])/2;
    this->spiel->texture.writeText(this->name, this->lifeRect, 10, this->lifecolor);
}
