#ifndef TEXTURE_CPP
#define TEXTURE_CPP

#include "./../header/rpg_definitions.hpp"
#include "./../header/debug.hpp"
#include "./../header/texture.hpp"

texture::texture(SDL_Renderer* renner){
    this->renner = renner;
    for(int i = 0; i < 5; i++){this->textureVector.push_back(nullptr);} // 0: map, 1: player, 2: npcs, 3: objects, 4: ui
}

void texture::renderTexture(int textureID, uint8_t kindOfTexture, SDL_Rect dst, int hight, int width){
    //this will ckeck if the texture file is loaded. if not it will load it
    if(this->textureVector[kindOfTexture] == nullptr){
        this->textureVector[kindOfTexture] = SDL_CreateTextureFromSurface(this->renner, IMG_Load(this->filepaths[kindOfTexture].c_str()));
    }
    int w, h;
    SDL_QueryTexture(this->textureVector[kindOfTexture], NULL, NULL, &w, &h);
    
    //the textures in the texture files are arranged 2 dimensional, but you only use 1 number the acces all of them. because of that the following lines will determine the position in the picture form the textureID
    this->rectangle.x = (textureID % (w/width))*width;
    this->rectangle.y = ((textureID*width)/(w))*hight;
    DEB_MSG_3(_T(this->rectangle.y/hight) + " " + _T(this->rectangle.x/width))
    DEB_MSG_3(_T(textureID) + "/" + _T(w) + "*" + _T(hight))
    
    //this will also render the payer. Sadly the player is bigger than the tiles, and the ui and other stuff will be bigger to. because of that you need the hight and width of a texture in the given file
    this->rectangle.h = hight;
    this->rectangle.w = width;
    DEB_MSG_3("loading at x: " + _T(this->rectangle.x) + " y: " + _T(this->rectangle.y))
    
    SDL_RenderCopy(this->renner, this->textureVector[kindOfTexture], &this->rectangle, &dst);
}

void texture::changeFilePath(uint8_t kindOfTexture, std::string newPath){
    //here the filename (oddly named newPath) will be added to the path of the texture folder
    this->filepaths[kindOfTexture] = "./resources/" + newPath;
    
    //this will reset the texture so the new one will be loaded the next time you need it
    this->textureVector[kindOfTexture] = nullptr;
}

void texture::drawRectangle(SDL_Rect dst, SDL_Color color, bool fill){
    SDL_SetRenderDrawColor(this->renner, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    if(fill){SDL_RenderFillRect(this->renner, &dst);}else{SDL_RenderDrawRect(this->renner, &dst);}
}

void texture::writeText(std::string message, SDL_Rect dst, int fontSize, SDL_Color color){
    TTF_Font *font = TTF_OpenFont("./resources/Ubuntu Mono derivative Powerline Bold.ttf", fontSize);
    if(font == nullptr){std::cout << TTF_GetError() << std::endl; return;}
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if(surf == nullptr){std::cout << "surfaceeror" << std::endl; TTF_CloseFont(font); return;}
    SDL_Texture *text = SDL_CreateTextureFromSurface(this->renner, surf);
    if(text == nullptr){std::cout << "textureerror" << std::endl;}
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    SDL_QueryTexture(text, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(this->renner, text, NULL, &dst);
}

#endif
