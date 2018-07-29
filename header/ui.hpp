#ifndef UI_HPP
#define UI_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <SDL2/SDL.h>

class ui{
protected:
    SDL_Color color = {0,0,0,0};
    SDL_Rect texturerect = {0,0,0,0};
    SDL_Rect barrect = {0,0,0,0};
    SDL_Rect goldrect = {0,0,0,0};
};

#endif
