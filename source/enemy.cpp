#include "./../header/enemy.hpp"
#include "./../header/game.hpp"

enemy::enemy(game* spiel, std::string kindOfTexture, int x, int y, std::string name, std::string onMap): character(spiel, kindOfTexture, x, y, name, onMap){
    this->rectangle.x = 600;
    this->rectangle.y = 600;

    this->rectangle.w = std::stoi(this->spiel->configuration["playerWidth"]);
    this->rectangle.h = std::stoi(this->spiel->configuration["playerHight"]);
}

void enemy::update(){
    this->rectangle.x = this->x + this->spiel->map.cx;
    this->rectangle.y = this->y + this->spiel->map.cy;
    this->lifeRect.x = this->x + this->spiel->map.cx - (50-std::stoi(this->spiel->configuration["playerWidth"]))/2;
    this->lifeRect.y = this->y + this->spiel->map.cy - 10;
    double pathx, pathy;
    this->getPath(&pathx, &pathy);
    this->x += pathx;
    this->y += pathy;
    this->animation++;
}

void enemy::getPath(double* x, double* y){
    *x = 0;
    *y = 0;
}
