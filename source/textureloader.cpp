#include "./../header/textureloader.hpp"
#include "./../header/game.hpp"

textureloader::textureloader(SDL_Renderer* renner, game* spiel){
    this->renner = renner;
    this->spiel = spiel;
}

void textureloader::renderTexture(int textureID, std::string kindOfTexture, SDL_Rect dst, int hight, int width){
    //this->textureMap.try_emplace(kindOfTexture, SDL_CreateTextureFromSurface(this->renner, IMG_Load(kindOfTexture.c_str())));
    if(!(this->textureMap.count(kindOfTexture))){
        this->textureMap[kindOfTexture] = SDL_CreateTextureFromSurface(this->renner, IMG_Load(kindOfTexture.c_str()));
    }
    
    int w, h;
    SDL_QueryTexture(this->textureMap[kindOfTexture], NULL, NULL, &w, &h);
    
    this->rectangle.x = (textureID % (w/width))*width;
    this->rectangle.y = ((textureID*width)/(w))*hight;
    this->rectangle.h = hight;
    this->rectangle.w = width;

    SDL_RenderCopy(this->renner, this->textureMap[kindOfTexture], &this->rectangle, &dst);
}

void textureloader::drawRectangle(SDL_Rect dst, SDL_Color color, bool fill){
    SDL_SetRenderDrawColor(this->renner, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    if(fill){SDL_RenderFillRect(this->renner, &dst);}else{SDL_RenderDrawRect(this->renner, &dst);}
}

void textureloader::writeText(std::string message, SDL_Rect dst, int fontSize, SDL_Color color){
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
