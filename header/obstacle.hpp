#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "./../src/tiles.cpp"
#define SCOPE_NAME "Obstacle"
#include "./debug.hpp"

class obstacle : public tile{
public:
    obstacle(const char* path, SDL_Renderer* renner, int x, int y);
    
    void draw(int x, int y);
};

#undef SCOPE_NAME
#endif
