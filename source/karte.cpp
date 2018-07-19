#ifndef KARTE_CPP
#define KARTE_CPP

#include "./../header/karte.hpp"
#include <fstream>
#include <vector>

karte::karte(const char* path,  texture* txp){
    this->textures = txp;
    std::ifstream readmap(path);
    if(!readmap.is_open()){DEB_ERR("Could not Open mapfile")}
    char c;
    std::string cs;
    std::vector<std::string> headline;
    readmap.get(c);
    if(c == '['){
        for(;;){
            readmap.get(c);
            if(c == '\n'){continue;}
            if(c == ' ') continue;
            if(c == ']'){headline.push_back(cs); cs = ""; DEB_MSG_1("i wanna break;") break;}
            if(c == ','){headline.push_back(cs);  cs = ""; continue;}
        cs+=c;
        }
    }else{DEB_ERR("mapfile not valid")}
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
    
    int mapwidth = stoi(headline[3]), maphight = stoi(headline[4]), numberOfNumbers = stoi(headline[5]);
    txp->changeFilePath(0,headline[7]);
    std::vector<int> mapLine;
    
    try{
        for(;;){readmap.get(c); if(c == '#'){readmap.get(c); break;}}
        cs = "";
        for(int y = 0; y < maphight; y++){
            for(int x = 0; x < mapwidth; x++){
                for(int posx = x; posx < x+numberOfNumbers; posx++){
                    readmap.get(c);
                    cs+=c;
                }
                mapLine.push_back(stoi(cs));
                cs = "";
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
    
    readmap.close();
}

void karte::draw(){
    for(int y = 0; y < this->hight; y++){
        this->rect.y = (y)*PICSIZE+this->cy;
        for(int x = 0; x < this->width; x++){
            this->rect.x = (x)*PICSIZE+this->cx;
            this->textures->renderTexture(this->tiles[y][x] , 0, this->rect, PICSIZE, PICSIZE);
        }
    }
}

void karte::changecxcy(double x, double y){
    this->cx-=x;
    this->cy-=y;
}

#endif
