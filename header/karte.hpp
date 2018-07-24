#ifndef KARTE_HPP
#define KARTE_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include "./texture.hpp"
//#include "./game.hpp" //does not compile with this
#include <vector>
#include "./config.hpp"


class karte{
public:
    /**
     * @brief will load the map
     * 
     * @param path it the path to the map file
     * @param txp is a pointer to your texturefolder
     */
    karte(const char* path, texture* txp, config* configuration);
    
    /**
     * @brief this is an empty contsructor. do not use
     */
    karte(){}
    
    /**
     * @brief this will draw the map
     */
    void draw();
    
    /**
     * @brief with this you can change the position of the map
     * 
     * @param x self explaining
     * @param y self explaining
     */
    void changecxcy(double x, double y);
    
    /**
     * @param with this you can get the collision value of the given tile
     * 
     * @param x is the x coordinate of the point you wanna know the collision value (in pixel (start to count in the top left corner))
     * @param y is the y coordinate of the point you wanna know the collision value (in pixel (start to count in the top left corner))
     * 
     * @return the collision value
     */
    uint8_t getCollisionValue(int x, int y);
private:
    //here the tiles are stored
    std::vector<std::vector<int>> tiles;
    
    //here the collision value is stored
    std::vector<std::vector<uint8_t>> collisions;
    
    //this is a pointer to the textureloader
    texture *textures;
    
    //this will be the width and the hight of the tile vector vector (the collision vector vector is slightly bigger)
    int width, hight;
    
    //with this you can change the position of of the map on the screen
    double cx, cy;
    
    config *configuration;
    
    //this rectangle is needed to draw the tiles 
    SDL_Rect rect = {0,0,0, 0};
};

#endif
