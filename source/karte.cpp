#include "./../header/karte.hpp"
#include "./../header/game.hpp" // is this ok?
#include <math.h>
#include <fstream>

karte::karte(game* spiel, const char* path){
    this->spiel = spiel;
    this->rect.h = std::stoi(this->spiel->configuration["picsize"]);
    this->rect.w = std::stoi(this->spiel->configuration["picsize"]);
    
    std::ifstream readmap(path);
    if(!readmap.is_open()){DEB_ERR("Could not Open mapfile")}
    
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
    
    if(this->width > std::stoi(this->spiel->configuration["width"])){
        this->cx = -(this->width-std::stoi(this->spiel->configuration["width"]))/2*std::stoi(this->spiel->configuration["picsize"]);
    }else{
        this->cx = (std::stoi(this->spiel->configuration["width"])-this->width)/2*std::stoi(this->spiel->configuration["picsize"]);
    }
    
    if(this->hight > std::stoi(this->spiel->configuration["hight"])){
        this->cy = -(this->hight-std::stoi(this->spiel->configuration["hight"]))/2*std::stoi(this->spiel->configuration["picsize"]);
    }else{
        this->cy = (std::stoi(this->spiel->configuration["hight"])-this->hight)/2*std::stoi(this->spiel->configuration["picsize"]);
    }
    
    DEB_MSG_1("cx: " + _T(this->cx) + " cy: " + _T(this->cy))
    DEB_MSG_1("picsize: " + _T(std::stoi(this->spiel->configuration["picsize"])))
    DEB_MSG_1("width: " + _T(std::stoi(this->spiel->configuration["width"])))
    DEB_MSG_1("hight: " + _T(std::stoi(this->spiel->configuration["hight"])))
    
    //the following will set up the collision vector vector
    std::vector<uint8_t> collisionline;
    for(int i = 0; i < this->width+2; i++){collisionline.push_back(1);}
    this->collision.push_back(collisionline);
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
            this->collision.push_back(collisionline);
            collisionline.clear();
        }
    }catch(...){DEB_ERR("mapfile not valid")}
    
    for(int i = 0; i < this->width+2; i++){collisionline.push_back(1);}
    this->collision.push_back(collisionline);
    collisionline.clear();
    
    DEB_MSG_1("Collision Hight: " + _T(this->collision.size()))
    DEB_MSG_1("Collision Width: " + _T(this->collision[0].size()))
    
    readmap.close();
}

void karte::draw(){
    for(int y = 0; y < this->hight; y++){
        this->rect.y = y * std::stoi(this->spiel->configuration["picsize"]) + this->cy;
        for(int x = 0; x < this->width; x++){
            this->rect.x = x * std::stoi(this->spiel->configuration["picsize"]) + this->cx;
            DEB_MSG_3("drawing at x: " + _T(this->rect.x) + " y: " + _T(this->rect.y))
            DEB_MSG_3("drawing with: picsize: " + _T(std::stoi(this->spiel->configuration["picsize"])) + " cx: " + _T(this->cx) + " cy: " + _T(this->cy) + "between 0 and " + _T(this->hight) + " and between 0 and " + _T(this->width))
            this->spiel->texture.renderTexture(this->tiles[y][x], this->spiel->configuration["mapPath"], this->rect, std::stoi(this->spiel->configuration["picsize"]), std::stoi(this->spiel->configuration["picsize"]));
        }
    }
}

void karte::changecxcy(double x, double y){
    this->cx-=x;
    this->cy-=y;
}

uint8_t karte::getCollisionValue(int x, int y){
    return this->collision[round(y/std::stoi(this->spiel->configuration["picsize"])-this->cy/std::stoi(this->spiel->configuration["picsize"])+1)][round(x/std::stoi(this->spiel->configuration["picsize"])-this->cx/std::stoi(this->spiel->configuration["picsize"])+1)];
}
