#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "./entity.hpp"

class character : public entity{
public:
    character(game* spiel, std::string kindOfTexture);
    character(void){}
    
    void draw();
    virtual void move(){}
protected:
    double animation = 0;
    uint8_t direction = 0;
};

#endif
