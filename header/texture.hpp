#include "./rpg_definitions.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>

using namespace std;

/**
 * @brief will draw the given texture at the given location
 * 
 * @param texturepointer is the texture you wanna draw
 * @param x is the x location
 * @param y is the y location
 */
void renderTexture(SDL_Texture* texturepointer, SDL_Renderer* renner, int x, int y){
  SDL_Rect dst;
  dst.x=x;
  dst.y=y;
  SDL_QueryTexture(texturepointer, NULL, NULL, &dst.w, &dst.h);
  SDL_RenderCopy(renner, texturepointer, NULL, &dst);
}

