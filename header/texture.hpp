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
    /**
     * @brief loads the textureloader with and SDL renderer 
     * 
     * @param renner is the sdl rendere you want
     */
    texture(SDL_Renderer* renner);
    
    /**
     * @brief that is an empty constructor. if you construct it this way dont use it
     */
    texture(){}
    
    /**
     * @brief this will render the given texture at the position of the given rectangle
     * 
     * @param textureID is the ID of the texture you wann draw
     * @param kindOfTexture specifies the kind of texture (see this->filepaths for detail)
     * @param dst is the rectangle specifying the position and size of the Texture you want to draw
     * @param hight is the hight of a texture in the given texture file
     * @param width is the width of a texture in the given texture file
     */
    void renderTexture(int textureID, uint8_t kindOfTexture, SDL_Rect dst, int hight, int width);
    
    /**
     * @brief with this you can change the path to the texture file you wanna load
     * 
     * @param kindofTexture  specifies the kind of texture (see this->filepaths for detail)
     * @param newPath is the name of the new fiel. for some odd reason this file have to in in the same folder
     */
    void changeFilePath(uint8_t kindOfTexture, std::string newPath);
private:
    //used to just take a part of the picture
    SDL_Rect rectangle = {0,0,PICSIZE, PICSIZE};
    
    //this is you renderer
    SDL_Renderer* renner;
    
    //a vector full of textures
    std::vector<SDL_Texture*> textureVector;
    
    //the paths to the texture files
    std::string filepaths[5] = {"./resources/map.png", "./resources/player.png", "./resources/npcs.png", "./resources/objects.png", "./resources/ui.png"}; //wanted to write this into rpg_definitions.hpp, but run into some problems
};

#endif
