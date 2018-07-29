#include "./../header/npc.hpp"
#include "./../header/game.hpp"

npc::npc(game* spiel, std::string kindOfTexture, std::string dialogPath): character(spiel, kindOfTexture), dialog(dialogPath){
    this->dialogRect.w = std::stoi(this->spiel->configuration["dialogWidth"]);
    this->dialogRect.h = std::stoi(this->spiel->configuration["dialogHight"]);
    
    this->rectangle.x = 600;
    this->rectangle.y = 600;
}

void npc::showDialog(bool fastItUp){
    this->spiel->texture.renderTexture(0, this->spiel->configuration["dialogTexture"], this->dialogRect, this->dialogRect.h, this->dialogRect.w);
}
