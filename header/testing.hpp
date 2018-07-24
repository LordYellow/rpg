#ifndef TESTING_HPP
#define TESTING_HPP

#define TESTING false

#if TESTING == true
    #include <chrono>
    #include <string> 
    #include <fstream>
    #include "./debug.hpp"
    
    void writeDownTestResults(std::string name, int result);
    void closeTest();
    
    #define STARTTEST auto begin = std::chrono::high_resolution_clock::now();
    #define STOPTEST(s) auto end = std::chrono::high_resolution_clock::now(); writeDownTestResults(s, std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count());
    #define CLOSETEST closeTest();  
#else
    #define STARTTEST
    #define STOPTEST(s)
    #define CLOSETEST 
#endif

#endif
