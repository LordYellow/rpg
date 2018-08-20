#include "./../header/npc.hpp"
#include "./../header/game.hpp"

npc::npc(game* spiel, std::string kindOfTexture, std::string dialogPath, int x, int y, std::string name, std::string onMap): character(spiel, kindOfTexture, x, y, name, onMap), dialog(dialogPath){
    this->dialogRect.w = std::stoi(this->spiel->configuration["dialogWidth"]);
    this->dialogRect.h = std::stoi(this->spiel->configuration["dialogHight"]);



    this->rectangle.x = 600;
    this->rectangle.y = 600;

    this->rectangle.w = std::stoi(this->spiel->configuration["playerWidth"]);
    this->rectangle.h = std::stoi(this->spiel->configuration["playerHight"]);
}

void npc::showDialog(){
    if(this->numberOfLettersToShow < 96) this->numberOfLettersToShow += 0.3;
    if(this->numberOfLettersToShow > 32 && this->messageRow2 == " "){this->numberOfLettersToShow = 96;
    }else if(this->numberOfLettersToShow > 64 && this->messageRow3 == " ") this->numberOfLettersToShow = 96;
    int nolts = round(this->numberOfLettersToShow);
    this->spiel->texture.renderTexture(0, this->spiel->configuration["dialogTexture"], this->dialogRect, this->dialogRect.h, this->dialogRect.w);
    this->spiel->texture.writeText(" " + this->messageRow1.substr(0,  nolts), this->textRectRow1, 14, this->textColor);
    if(nolts > 32) this->spiel->texture.writeText(" " + this->messageRow2.substr(0, nolts-32), this->textRectRow2, 14, this->textColor);
    if(nolts > 64) this->spiel->texture.writeText(" " + this->messageRow3.substr(0, nolts-64), this->textRectRow3, 14, this->textColor);
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

    this->lifeRect.x = this->x + this->spiel->map.cx - (50-std::stoi(this->spiel->configuration["playerWidth"]))/2;
    this->lifeRect.y = this->y + this->spiel->map.cy - 10;
}
