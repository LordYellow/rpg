#include "./../header/entity.hpp"
#include "./../header/game.hpp"

entity::entity(game* spiel, std::string kindOfTexture, int x, int y){
    this->kindOfTexture = kindOfTexture;
    this->spiel = spiel;
    this->x = x;
    this->y = y;
}
