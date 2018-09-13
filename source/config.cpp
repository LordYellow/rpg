#include "./../header/config.hpp"
#include <fstream>

config::config(){
    std::ifstream readconfig("./../configfile");
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
                    DEB_MSG_1("1. Argument: " + cs1)
                    DEB_MSG_1("2. Argument: " + cs2)
                    this->configmap[cs1] = cs2;
                    DEB_MSG_3("seccond config break") 
                    break;
                }
                if(readconfig.eof()){DEB_ERR("Config file has unexpectedly ended. Did you forget ']'?")}
                if(!readconfig.good()) DEB_ERR("Error reading file")
                cs2+=c;
            }
        }
        cs1 = "";
        cs2 = "";
    }
}
