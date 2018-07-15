#ifndef TILES_H
#define TILES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class tile{
public:
    tile():image(NULL),texture(NULL),renner(NULL){}
    tile(const char* path, SDL_Renderer* renner);
    SDL_Surface *image; 
    SDL_Texture *texture;
    SDL_Renderer *renner;
    SDL_Rect dst;
    
    /**
     * @brief this will draw the tile at the given position
     */
    void draw(int x, int y);
};

#endif
