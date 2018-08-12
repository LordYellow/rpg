#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "./character.hpp"
#include "./ui.hpp"
#include "./npc.hpp"

class player : public character, public ui{
public:
    player(game* spiel, std::string kindOfTexture, int x, int y);
    player(void){}
    
    void update();
    bool walkable(int x, int y);
    void doMove(int x, int y);
    void showUi();
    void interact(); 
private:
    double life = 100;
    double ausdauer = 100;
    double gold = 0;
    double experience = 20;
    double distanceToNpc(npc npcForDistance);
};

#endif
