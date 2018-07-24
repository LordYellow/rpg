#ifndef UI_CPP
#define UI_CPP

#include "./../header/ui.hpp"

ui::ui(config* configuration, texture* textures){
    this->configuration = configuration;
    this->textures = textures;
    
    this->rectangle.x = SCREENWIDTH-232;
    this->rectangle.y = SCREENHIGHT-78;
    
    this->barrect.x = this->rectangle.x+119;
    
    this->goldrect.x = this->rectangle.x+26;
    this->goldrect.y = this->rectangle.y+8;
}

void ui::draw(double life, double ausdauer, double gold, double experience){
    this->textures->renderTexture(0,4,this->rectangle, 78, 232);
    
    //lifebar
    this->color.b = 0;
    if(life > 50){
        this->color.r = 255-2.55*2*life;
        this->color.g = 255;
    }else{
        this->color.r = 255;
        this->color.g = 2.55*2*life;
    }
    this->barrect.y = this->rectangle.y+14;
    this->barrect.w = life;
    this->textures->drawRectangle(this->barrect, this->color, true);
    
    //staminabar 
    this->color.r = 230;
    this->color.g = 230;
    this->color.b = 2;
    this->barrect.y = this->rectangle.y + 36;
    this->barrect.w = ausdauer;
    this->textures->drawRectangle(this->barrect, this->color, true);
    
    //experiencebar
    this->color.r = 10;
    this->color.g = 200;
    this->color.b = 30;
    this->barrect.y = this->rectangle.y + 56;
    this->barrect.w = experience;
    this->textures->drawRectangle(this->barrect, this->color, true);
    
    //gold
    this->color.r = 232;
    this->color.g = 168;
    this->color.b = 0;
    this->textures->writeText("12", this->goldrect, 40, this->color);
}
#endif
