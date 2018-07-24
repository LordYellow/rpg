#ifndef KARTE_CPP
#define KARTE_CPP

#include "./../header/karte.hpp"
#include <fstream>
#include <vector>
#include <math.h>

karte::karte(const char* path,  texture* txp, config* configuration){
    this->configuration = configuration;
    this->textures = txp;
    std::ifstream readmap(path);
    if(!readmap.is_open()){DEB_ERR("Could not Open mapfile")}
    
    this->rect.h = PICSIZE;
    this->rect.w = PICSIZE;
    
    //used to store the values of the tiles (later for the collision value)
    char c;
    std::string cs;
    
    
    std::vector<std::string> headline;
    //this will read the headline and store the information
    for(;;){readmap.get(c); if(c == '['){ break;}else{if(readmap.eof()) DEB_ERR("File ended without Headline declaration")}}
    for(;;){
        readmap.get(c);
        if(c == '\n'){continue;}
        if(c == ' ') continue;
        if(c == ']'){headline.push_back(cs); cs = ""; DEB_MSG_1("i wanna break;") break;}
        if(c == ','){headline.push_back(cs);  cs = ""; continue;}
        cs+=c;
        if(!readmap.good()) DEB_ERR("Error reading file")
    }
    if(headline.size() != 9){DEB_ERR("mapfile not valid")}
    DEB_MSG_1("Autor: " + headline[0])
    DEB_MSG_1("Datum: " + headline[1])
    DEB_MSG_1("Uhrzeit: " + headline[2])
    DEB_MSG_1("Width " + headline[3])
    DEB_MSG_1("Hight " + headline[4])
    DEB_MSG_1("Number of Numbers:  " + headline[5])
    DEB_MSG_1("Kartenname: " + headline[6])
    DEB_MSG_1("Kartentyp: " + headline[7])
    DEB_MSG_1("Colison Definition at: " + headline[8])
    
    //now the important information of the headline will be stored
    int mapwidth = stoi(headline[3]), maphight = stoi(headline[4]), numberOfNumbers = stoi(headline[5]);
    txp->changeFilePath(0,headline[7]);
    std::vector<int> mapLine;
    
    //now it will read the tile part of the mapfile
    try{
        for(;;){readmap.get(c); if(c == '#'){readmap.get(c); break;}else{if(readmap.eof()) DEB_ERR("File ended without Map declaration")}}
        cs = "";
        for(int y = 0; y < maphight; y++){
            for(int x = 0; x < mapwidth; x++){
                for(int posx = x; posx < x+numberOfNumbers; posx++){
                    readmap.get(c);
                    cs+=c;
                }
                mapLine.push_back(stoi(cs));
                cs = "";
                if(!readmap.good()) DEB_ERR("Error reading file")
            }
            readmap.get(c);
            this->tiles.push_back(mapLine);
            mapLine.clear();
        }
    }catch(...){DEB_ERR("mapfile not valid")}

    this->width = mapwidth;
    this->hight = maphight;
    
    if(this->width > WIDTH){
        this->cx = -(this->width-WIDTH)/2*PICSIZE;
    }else{
        this->cx = (WIDTH-this->width)/2*PICSIZE;
    }
    
    if(this->hight > HIGHT){
        this->cy = -(this->hight-HIGHT)/2*PICSIZE;
    }else{
        this->cy = (HIGHT-this->hight)/2*PICSIZE;
    }
    
    //the following will set up the collision vector vector
    std::vector<uint8_t> collisionline;
    for(int i = 0; i < this->width+2; i++){collisionline.push_back(1);}
    this->collisions.push_back(collisionline);
    collisionline.clear();
    
    try{
        for(;;){readmap.get(c); if(c == headline[8][0]){readmap.get(c); break;}else if(readmap.eof()) DEB_ERR("File ended without Collision Declaration")}
        cs = "";
        for(int y = 0; y < maphight; y++){
            collisionline.push_back(1);
            for(int x = 0; x < mapwidth; x++){
                for(int i = 0; i < 2; i++){
                    readmap.get(c);
                    cs+=c;
                    if(!readmap.good()) DEB_ERR("Error reading file")
                }
                collisionline.push_back(stoi(cs));
                cs = "";
            }
            readmap.get(c);
            collisionline.push_back(1);
            this->collisions.push_back(collisionline);
            collisionline.clear();
        }
    }catch(...){DEB_ERR("mapfile not valid")}
    
    for(int i = 0; i < this->width+2; i++){collisionline.push_back(1);}
    this->collisions.push_back(collisionline);
    collisionline.clear();
    
    DEB_MSG_1("Collision Hight: " + _T(this->collisions.size()))
    DEB_MSG_1("Collision Width: " + _T(this->collisions[0].size()))
    
    readmap.close();
}

void karte::draw(){
    for(int y = 0; y < this->hight; y++){
        this->rect.y = (y)*PICSIZE+this->cy;
        for(int x = 0; x < this->width; x++){
            this->rect.x = (x)*PICSIZE+this->cx;
            //now the texture will be drawn at the position of the rectangle (the rectangle will move)
            this->textures->renderTexture(this->tiles[y][x] , 0, this->rect, PICSIZE, PICSIZE);
        }
    }
}

void karte::changecxcy(double x, double y){
    this->cx-=x;
    this->cy-=y;
}

uint8_t karte::getCollisionValue(int x, int y){
        DEB_MSG_3("y: " + _T(y/PICSIZE-this->cy/PICSIZE+1) + " x: " + _T(x/PICSIZE-this->cx/PICSIZE+1))
        return this->collisions[round(y/PICSIZE-this->cy/PICSIZE+1)][round(x/PICSIZE-this->cx/PICSIZE+1)];
}

#endif
