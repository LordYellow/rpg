#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "./entity.hpp"

class character : public entity{
public:
    character(game* spiel, std::string kindOfTexture, int x, int y);
    character(void){}
    
    void draw();
    virtual void update();
protected:
    double animation = 0;
    uint8_t direction = 0;
};

#endif
