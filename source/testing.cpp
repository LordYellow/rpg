#ifndef TESTING_CPP
#define TESTING_CPP

#include "./../header/debug.hpp"
#include "./../header/testing.hpp"
#include <fstream>

std::ofstream writeDownResults("testResults", std::ios::app);

void writeDownTestResults(std::string name, int result){
    if(writeDownResults.good()){
        writeDownResults << "[" << name << "|" << result << "]";
    }else{
        DEB_ERR("Unable to write down Test Results")
    }
}

void closeTest(){
    if(writeDownResults.good()){
        writeDownResults << std::endl;
        writeDownResults.close();
    }else{
        DEB_ERR("Unable to write down Test Results")
    }
}

#endif
