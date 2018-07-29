#ifndef DIALOG_HPP
#define DIALOG_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <fstream>
#include <SDL2/SDL.h>

class dialog{
public:
    dialog(std::string dialogPath);
    dialog(void){}
    
    virtual void showDialog(bool fastItUp){}
protected:
    int currentPosition = 0;
    std::string currentMessage;
    std::ifstream readDialog;
    int numberOfLines;
    SDL_Rect dialogRect = {0,0,0,0};
};

#endif
