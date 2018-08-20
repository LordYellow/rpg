#include "./../header/dialog.hpp"
#include <algorithm>
#include <array>

dialog::dialog(std::string dialogPath){
    this->readDialog.open(dialogPath);
    if(!(this->readDialog.is_open())) DEB_ERR("Could not Open Dialog file")
    std::getline(this->readDialog, this->currentMessage);
}

void dialog::getMessageRows(){
    std::array<std::string, 3> stringarray = {" ", " ", " "};
    for(int i = 0; i < 3; i++){
        int position = this->currentPosition;
        std::string word;
        for(int a = position; a < position+32; a++){
            if(a > this->currentMessage.length()-1) break;
            word += this->currentMessage[a];
            if(this->currentMessage[a] == ' ' || a == this->currentMessage.length()-1){
                this->currentPosition = a+1;
                stringarray[i] = word;
            }
        }
    }
    this->messageRow1 = stringarray[0];
    this->messageRow2 = stringarray[1];
    this->messageRow3 = stringarray[2];
}

std::string dialog::getMessageRow1(){return this->messageRow1;}
