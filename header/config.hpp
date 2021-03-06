#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "./rpg_definitions.hpp"
#include "./debug.hpp"
#include <unordered_map>

class config{
public:
    config();
    
    std::unordered_map<std::string, std::string> configmap;
    
    std::string& operator[](std::string idx){return this->configmap[idx];}
};

#endif
