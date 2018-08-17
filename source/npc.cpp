#include "./../header/npc.hpp"
#include "./../header/game.hpp"

npc::npc(game* spiel, std::string kindOfTexture, std::string dialogPath, int x, int y): character(spiel, kindOfTexture, x, y), dialog(dialogPath){
    this->dialogRect.w = std::stoi(this->spiel->configuration["dialogWidth"]);
    this->dialogRect.h = std::stoi(this->spiel->configuration["dialogHight"]);



    this->rectangle.x = 600;
    this->rectangle.y = 600;

    this->rectangle.w = std::stoi(this->spiel->configuration["playerWidth"]);
    this->rectangle.h = std::stoi(this->spiel->configuration["playerHight"]);
}

void npc::showDialog(){
    this->spiel->texture.renderTexture(0, this->spiel->configuration["dialogTexture"], this->dialogRect, this->dialogRect.h, this->dialogRect.w);
    this->spiel->texture.writeText(this->messageRow1, this->textRectRow1, 14, this->textColor);
    this->spiel->texture.writeText(this->messageRow2, this->textRectRow2, 14, this->textColor);
    this->spiel->texture.writeText(this->messageRow3, this->textRectRow3, 14, this->textColor);
}

void npc::update(){
    if(this->displayDialog){
        this->showDialog();
    }
    this->rectangle.x = this->x + this->spiel->map.cx;
    this->rectangle.y = this->y + this->spiel->map.cy;

    this->dialogRect.x = this->x + this->spiel->map.cx + this->rectangle.w;
    this->dialogRect.y = this->y + this->spiel->map.cy - this->dialogRect.h + this->dialogRect.h/4;

    this->textRectRow1.x = this->dialogRect.x + 35;
    this->textRectRow1.y = this->dialogRect.y + 20;
    this->textRectRow2.x = this->dialogRect.x + 35;
    this->textRectRow2.y = this->dialogRect.y + 40;
    this->textRectRow3.x = this->dialogRect.x + 35;
    this->textRectRow3.y = this->dialogRect.y + 60;
}
