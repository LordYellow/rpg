#include "./../header/entity.hpp"
#include "./../header/game.hpp"

entity::entity(game* spiel, std::string kindOfTexture){
    this->kindOfTexture = kindOfTexture;
    this->spiel = spiel;
}
