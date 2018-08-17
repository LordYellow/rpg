#include "./../header/game.hpp"

game::game(void){
    //SDL init stuff
    if(SDL_Init(SDL_INIT_VIDEO) != 0){std::cout << "error: " << SDL_GetError() << std::endl; return;}
    if(TTF_Init() != 0){std::cout << "error" << std::endl; SDL_Quit(); return;}
    this->win = SDL_CreateWindow("Titel",100,200,std::stoi(this->configuration["screenwidth"]),std::stoi(this->configuration["screenhight"]),SDL_WINDOW_SHOWN);
    if(win == nullptr){std::cout << "winerror: " << SDL_GetError() << std::endl; SDL_Quit(); return;}
    this->renner = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renner == nullptr){SDL_DestroyWindow(this->win); std::cout << "renderererror: " << SDL_GetError() << std::endl; SDL_Quit(); return;}
}

game::~game(void){
    SDL_DestroyRenderer(this->renner);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
}

void game::update(){
    DEB_MSG_3("running")

    SDL_SetRenderDrawColor(this->renner, 0, 0, 0, 0);
    SDL_RenderClear(this->renner);

    this->map.draw();
    for(size_t i = 0; i < this->npcvector.size(); i++){this->npcvector[i].draw();}
    this->spieler.draw();

    SDL_RenderPresent(this->renner);\
    SDL_Delay(1);
}

void game::handleEvents(){
    this->lastaction = this->keys[SDLK_e];
    if(SDL_PollEvent(&this->event)){
        switch(this->event.type){
            case SDL_QUIT: this->stateOfGame = GAMEOVER; break;
            case SDL_KEYDOWN: this->keys[this->event.key.keysym.sym] = 1; break;
            case SDL_KEYUP: this->keys[this->event.key.keysym.sym] = 0; break;
        }
    }

    switch(this->stateOfGame){
        case RUNNING:
            if(keys[SDLK_w]){(this->spieler).doMove(0,-1);}
            if(keys[SDLK_s]){(this->spieler).doMove(0,1);}
            if(keys[SDLK_a]){(this->spieler).doMove(-1,0);}
            if(keys[SDLK_d]){(this->spieler).doMove(1,0);}
            if(keys[SDLK_e] && keys[SDLK_e] != lastaction){(this->spieler).interact();}
            break;
        case DIALOG:
            if(keys[SDLK_e] && keys[SDLK_e] != lastaction){
                this->npcvector[this->spieler.talkingto].getMessageRows();
                if(this->npcvector[this->spieler.talkingto].getMessageRow1() == " "){
                    this->npcvector[this->spieler.talkingto].displayDialog = false;
                    this->npcvector[this->spieler.talkingto].currentPosition = 0;
                    this->stateOfGame = RUNNING;
                }
            }
            break;
        default: break;
    }
}

void game::load(const char* path){
    this->map = karte(this, "./maps/testmap");
    this->texture = textureloader(this->renner, this);
    this->spieler = player(this, "./resources/player.png", -100,-50);
    this->npcvector.push_back(npc(this, "./resources/player.png", "./testdialog",200,500));
}
