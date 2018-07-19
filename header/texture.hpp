#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <vector>
#include <string>

class texture{
public:
    texture(SDL_Renderer* renner);
    texture(){}
    
    void renderTexture(int textureID, uint8_t kindOfTexture, SDL_Rect dst, int hight, int width);
    SDL_Rect rectangle = {0,0,PICSIZE, PICSIZE};
    void changeFilePath(uint8_t kindOfTexture, std::string newPath);
private:
    SDL_Renderer* renner;
    std::vector<SDL_Texture*> textureVector;
    std::string filepaths[5] = {"./resources/map.png", "./resources/player.png", "./resources/npcs.png", "./resources/objects.png", "./resources/ui.png"}; //wanted to write this into rpg_definitions.hpp, but run into some problems
};

#endif
