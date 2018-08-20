#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "./entity.hpp"

class character : public entity{
public:
    character(game* spiel, std::string kindOfTexture, int x, int y, std::string name, std::string onMap);
    character(void){}

    void draw();
    virtual void update();
    virtual void showName();
protected:
    double animation = 0;
    uint8_t direction = 0;
    double life = 100;
    std::string name;
    SDL_Rect lifeRect = {0,0,0,0};
    SDL_Color lifecolor = {0,0,0,0};
    std::string onMap;
};

#endif
