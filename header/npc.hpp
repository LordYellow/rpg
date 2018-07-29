#ifndef NPC_HPP
#define NPC_HPP

#include "./character.hpp"
#include "./dialog.hpp"

class npc : public character, public dialog{
public:
    npc(game* spiel, std::string kindOfTexture, std::string dialogPath);
    npc(void){}
    
    void showDialog(bool fastItUp);
};

#endif
