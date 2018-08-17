#include "./../header/npc.hpp"
#include "./../header/game.hpp"

npc::npc(game* spiel, std::string kindOfTexture, std::string dialogPath, int x, int y): character(spiel, kindOfTexture, x, y), dialog(dialogPath){
    this->dialogRect.w = std::stoi(this->spiel->configuration["dialogWidth"]);
    this->dialogRect.h = std::stoi(this->spiel->configuration["dialogHight"]);

    this->rectangle.x = 600;
    this->rectangle.y = 600;

    this->dialogRect.y = std::stoi(spiel->configuration["screenhight"]) - std::stoi(spiel->configuration["dialogHight"]);

    this->rectangle.w = std::stoi(this->spiel->configuration["playerWidth"]);
    this->rectangle.h = std::stoi(this->spiel->configuration["playerHight"]);
}

void npc::showDialog(){
    this->spiel->texture.renderTexture(0, this->spiel->configuration["dialogTexture"], this->dialogRect, this->dialogRect.h, this->dialogRect.w);
}

void npc::update(){
    if(this->displayDialog){
        this->showDialog();
    }
    this->rectangle.x = this->x + this->spiel->map.cx;
    this->rectangle.y = this->y + this->spiel->map.cy;
}
