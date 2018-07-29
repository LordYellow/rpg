#include "./../header/player.hpp"
#include "./../header/game.hpp"

player::player(game* spiel, std::string kindOfTexture): character(spiel, kindOfTexture){
    this->rectangle.x = std::stoi(this->spiel->configuration["screenwidth"])/2-std::stoi(this->spiel->configuration["playerWidth"])/2;
    this->rectangle.y = std::stoi(this->spiel->configuration["screenhight"])/2-std::stoi(this->spiel->configuration["playerHight"])/2;
    this->rectangle.w = std::stoi(this->spiel->configuration["playerWidth"]);
    this->rectangle.h = std::stoi(this->spiel->configuration["playerHight"]);
    
    this->texturerect.x = std::stoi(this->spiel->configuration["screenwidth"])-std::stoi(this->spiel->configuration["uiWidth"]);
    this->texturerect.y = std::stoi(this->spiel->configuration["screenhight"])-std::stoi(this->spiel->configuration["uiHight"]);
    this->texturerect.h = std::stoi(this->spiel->configuration["uiHight"]);
    this->texturerect.w = std::stoi(this->spiel->configuration["uiWidth"]);
    
    this->barrect.x = this->texturerect.x+119;
    
    this->goldrect.x = this->texturerect.x+26;
    this->goldrect.y = this->texturerect.y+8;
    
    this->barrect.h = 6;
    this->goldrect.h = 32;
}

void player::update(){
    //the player doesnt need a update function, cause his movement is handelt by another function (doMove). Because of that i decided to put the ui stuff in there
    this->showUi();
}

void player::doMove(int x, int y){
    if(x == 0){
        this->direction = ((y>0)?0:3);
    }else{
        this->direction = ((x>0)?2:1);
    }
    if(this->walkable(x, y)){
        this->spiel->map.changecxcy(x*std::stoi(this->spiel->configuration["speed"]), y*std::stoi(this->spiel->configuration["speed"]));
    }
    this->animation+=0.1;
}

bool player::walkable(int x, int y){
    //placeholder
    //uint8_t ptw = this->spiel->map.getCollisionValue((rectangle.x + x*std::stoi(this->spiel->configuration["picsize"])/32 + 16), (rectangle.y + y*std::stoi(this->spiel->configuration["picsize"])/32 + 32));
    return true;
}

void player::showUi(){
    this->spiel->texture.renderTexture(0,this->spiel->configuration["uiTexture"],this->texturerect, 78, 232);
    
    //lifebar
    this->color.b = 0;
    if(life > 50){
        this->color.r = 255-2.55*2*this->life;
        this->color.g = 255;
    }else{
        this->color.r = 255;
        this->color.g = 2.55*2*this->life;
    }
    this->barrect.y = this->texturerect.y+14;
    this->barrect.w = this->life;
    this->spiel->texture.drawRectangle(this->barrect, this->color, true);
    
    //staminabar 
    this->color.r = 230;
    this->color.g = 230;
    this->color.b = 2;
    this->barrect.y = this->texturerect.y + 36;
    this->barrect.w = this->ausdauer;
    this->spiel->texture.drawRectangle(this->barrect, this->color, true);
    
    //experiencebar
    this->color.r = 10;
    this->color.g = 200;
    this->color.b = 30;
    this->barrect.y = this->texturerect.y + 56;
    this->barrect.w = this->experience;
    this->spiel->texture.drawRectangle(this->barrect, this->color, true);
    
    //gold
    this->color.r = 232;
    this->color.g = 168;
    this->color.b = 0;
    this->spiel->texture.writeText("12", this->goldrect, 40, this->color);
}
