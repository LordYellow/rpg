#include "./../header/dialog.hpp"
#include <algorithm>

dialog::dialog(std::string dialogPath){
    this->readDialog.open(dialogPath);
    if(!(this->readDialog.is_open())) DEB_ERR("Could not Open Dialog file") 
    this->numberOfLines = std::count(std::istreambuf_iterator<char>(this->readDialog), std::istreambuf_iterator<char>(), '\n');
    std::getline(this->readDialog, this->currentMessage);
}
