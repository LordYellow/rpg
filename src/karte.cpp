#ifndef KARTE_CPP
#define KARTE_CPP

#include "./../header/rpg_definitions.hpp"
#include "./../header/karte.hpp"
#include "SDL2/SDL.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

karte::karte ( const char* path, SDL_Renderer* renner) {
    this->renner = renner;
    ifstream readMap(path);
    if(!readMap.is_open()){DEB_ERR("Could not open file")}
    string line;
    vector<tile> tv;
    while(getline(readMap, line) && line != "end"){ 
        //reads the file until it ends 
        if(line.size() == 0){ //if the line is empty it will end the current "line"
            DEB_MSG_2(_T(tv.size()) + " elements pushed in field")
            this->field.push_back(tv);
            DEB_MSG_2(_T(field.size()))
            tv.clear();
        }else{ //else it will create a new tile in the current line with the given texture
            string s = "./images/mapimages/" + line;
            tv.push_back(tile(s.c_str(), this->renner));
            DEB_MSG_3("Pushed Tile in Vector")
        }

    }
    //the following is to center the map when drawn 
    this->mapWidth = this->field.size();
    this->mapHight = this->field[0].size();
    DEB_MSG_1(_T(this->mapWidth) + " = mapWidth")
    DEB_MSG_1(_T(this->mapHight) + " = mapHight")
    //dont question it
    this->spy = HIGHT/PICSIZE/2-this->mapWidth;
    this->spx = WIDTH/PICSIZE/2-this->mapHight/2;
    DEB_MSG_1(_T(this->spx) + " = spx")
    DEB_MSG_1(_T(this->spy) + " = spy")
}

void karte::draw(int cx, int cy){
    for(int y = 0; y < this->mapWidth; y++){
        for(int x = 0; x < this->mapHight; x++){
            this->field[y][x].draw((x+cx+this->spx)*PICSIZE, (y+cy+this->spy)*PICSIZE);
            DEB_MSG_3("drawing at: " + _T((x+cx+this->spx)*PICSIZE) + " " + _T((y+cy+this->spy)*PICSIZE))
        }
    }
}

#endif
