#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <SDL2/SDL.h>
#include "./texture.hpp"

class enemy{
public:
    enemy(void){}
    enemy(int posX, int posY, uint8_t direction, std::string name, int kindofTexture, texture* textures);
    enemy(int posX, int posY, uint8_t direction, std::string name, int kindofTexture, int targetX, int targetY, int speed, texture* textures);
    
    void update();
    
private:
    int posX, posY, targetX, targetY;
    
    //this is the direction you are looking too
    uint8_t direction = 0;
    
    //this number indicates the current animation
    double animation = 0;
    
    //this is a rectangle
    SDL_Rect rectangle = {400,300,32,48};
    
    SDL_Rect lifebar = {0,0,100,6};
    
    SDL_Color color = {0,0,0,0};
    
    bool moving;
    
    std::string name;
    
    double life = 23;
    
    int kindofTexture;
    
    int speed;
    
    void move();
    
    int cx = 0, cy = 0;
    
    texture* textures;
};

#endif
