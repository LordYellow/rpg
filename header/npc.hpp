#ifndef NPC_HPP
#define NPC_HPP

#include "./character.hpp"
#include "./dialog.hpp"

class npc : public character, public dialog{
public:
    npc(game* spiel, std::string kindOfTexture, std::string dialogPath, int x, int y, std::string name, std::string onMap);
    npc(void){}

    void showDialog();
    void update();

    bool displayDialog = false;
};

#endif
