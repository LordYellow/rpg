#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include "./texture.hpp"
#include "./karte.hpp"
#include <map>

class player{
public:
    /**
     * @brief constructs the player
     * 
     * @param tx is a pointer to the textureloader
     * @param map is a pointer to the map
     * @param eventmap is a pointer to the eventmap from the game class
     */
    player(texture* tx, karte* map, std::map<int, int>* eventmap);
    
    /**
     * @brief this is a empty constructor. do not use
     */
    player(){}
    
    /**
     * @brief draws the player
     */
    void draw();
    
    /**
     * @brief moves the player in the given direction
     * 
     * @param x is the x value you wanna move. i recommend using only -1, 0 and 1
     * @param y is the y value you wanna move. i recommend using only -1, 0 and 1
     */
    void move(int x, int y);
private:
    texture *textures;
    karte *map;
    std::map<int, int> *eventmap;
    
    //this is the direction you are looking too
    uint8_t direction = 0;
    
    //this number indicates the current animation
    double animation = 0;
    
    //this is a rectangle
    SDL_Rect rectangle = {SCREENWIDTH/2,SCREENHIGHT/2,32,48};
    
    /**
     * @brief this determines if you can move in the given direction
     * 
     * @param x is the x value you wanna move. i recommend using only -1, 0 and 1
     * @param y is the y value you wanna move. i recommend using only -1, 0 and 1
     * 
     * @return true if you can move
     */
    bool walkable(int x, int y);
};

#endif
