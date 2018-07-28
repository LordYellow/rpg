#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>

class game;

class textureloader{
public:
    textureloader(SDL_Renderer* renner, game* spiel);
    textureloader(void){}
    
    void renderTexture(int textureID, std::string kindOfTexture, SDL_Rect dst, int hight, int width);
    
    void drawRectangle(SDL_Rect dst, SDL_Color color, bool fill);
    
    void writeText(std::string message, SDL_Rect dst, int fontSize, SDL_Color color);
private:
    SDL_Rect rectangle = {0,0,0,0};
    SDL_Renderer* renner;
    std::unordered_map<std::string, SDL_Texture*> textureMap;
    game* spiel;
};

#endif
