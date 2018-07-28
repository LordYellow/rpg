#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "./character.hpp"

class player : public character{
public:
    player(game* spiel, std::string kindOfTexture);
    player(void){}
    
    void move();
    bool walkable(int x, int y);
    void doMove(int x, int y);
};

#endif
