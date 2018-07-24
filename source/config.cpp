#ifndef CONFIG_CPP
#define CONFIG_CPP

#include "./../header/config.hpp"
#include <fstream>

config::config(){
    this->configmap["picsize"] = 32;
    this->configmap["hight"] = 20;
    this->configmap["width"] = 35;
    this->configmap["screenhight"] = 20*32;
    this->configmap["screenwidth"] = 35*32;
    this->configmap["speed"] = 10;
    
    std::ifstream readconfig(CONFIGPATH);
    if(!(readconfig.is_open())) DEB_ERR("Could not Open config file")
    char c;
    std::string cs1, cs2;

    while(!readconfig.eof()){
        readconfig.get(c);
        if(c == '['){
            for(;;){
                readconfig.get(c);
                if(c == '\n')continue;
                if(c == ' ') continue;
                if(c == '='){
                    DEB_MSG_3("first config break") 
                    break;
                }
                if(readconfig.eof()){DEB_ERR("Config file has unexpectedly ended. Did you forget ']'?")}
                if(!readconfig.good()){DEB_ERR("Error reading file")}
                cs1+=c;
            }
            for(;;){
                readconfig.get(c);
                if(c == '\n')continue;
                if(c == ' ') continue;
                if(c == ']'){
                    bool viable = true;
                    DEB_MSG_1("1. Argument: " + cs1)
                    DEB_MSG_1("2. Argument: " + cs2)
                    for(int i = 0; i < cs1.size(); i++){if(!isalpha(cs1[i])){DEB_ERR("1. Argument is not Valid") viable = false;}}
                    for(int i = 0; i < cs2.size(); i++){if(!isdigit(cs2[i])){DEB_ERR("2. Argument is not Valid") viable = false;}}
                    if(viable){
                        DEB_MSG_1("Arguments are Valid")
                        this->configmap[cs1] = std::stoi(cs2);
                    }
                    DEB_MSG_3("seccond config break") 
                    break;
                }
                if(readconfig.eof()){DEB_ERR("Config file has unexpectedly ended. Did you forget ']'?")}
                if(!readconfig.good()) DEB_ERR("Error reading file")
                cs2+=c;
            }
        }
    }
}

#endif
