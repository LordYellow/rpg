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

    virtual void showDialog(){}
    void getMessageRows();
    std::string getMessageRow1();
    int currentPosition = 0;
protected:
    std::string currentMessage, messageRow1, messageRow2, messageRow3;
    std::ifstream readDialog;
    int numberOfLines;
    SDL_Rect dialogRect = {0,0,0,0};
    SDL_Rect textRectRow1 = {0,0,200,50};
    SDL_Rect textRectRow2 = {0,0,200,50};
    SDL_Rect textRectRow3 = {0,0,200,50};
    SDL_Color textColor = {0,0,0,0};
};

#endif
