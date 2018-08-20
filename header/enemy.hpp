#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "./character.hpp"

class enemy : public character{
public:
    enemy(game* spiel, std::string kindOfTexture, int x, int y, std::string name, std::string onMap);
    enemy(void){}

    void update();
private:
    void getPath(double* x, double* y);
};

#endif
