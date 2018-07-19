/*
#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <string>
#include <iostream>
#include <time.h>
#include <iomanip>

#define MSG_LEN  90
#define PAT_LEN  15

std::string _PT() {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    char buff[100];
    strftime(buff, sizeof buff, "%d.%m.%Y  %T", gmtime(&ts.tv_sec));
    std::cout << " [" << buff << "." << std::to_string(ts.tv_nsec).substr(0,5) << " UTC]" ;
    return "";
}

#ifndef SCOPE_NAME
    #define SCOPE_NAME 0
#endif

#define _S(s)                      std::string(s)
#define _T(s)                      std::to_string(s)

#define DEBUG_ESCAPE               _S("\033[")
#define DEBUG_SINGLE_C(c)          (DEBUG_ESCAPE+_T(c)+"m")

#define DEBUG_COLOR_FG_RGB(r,g,b)  (DEBUG_ESCAPE+_S("38;2;")+_T(r)+_S(";")+ \
                                    _T(g)+_S(";")+_T(b)+_S("m"))
#define DEBUG_COLOR_BG_RGB(r,g,b)  (DEBUG_ESCAPE+_S("48;2;")+_T(r)+_S(";")+ \
                                    _T(g)+_S(";")+_T(b)+_S("m"))

#define DEBUG_RESET                DEBUG_SINGLE_C( 0)

#define DEBUG_NORMALIZE            DEBUG_SINGLE_C(22)
#define DEBUG_NORMALIZE_2          DEBUG_SINGLE_C(23)
#define DEBUG_NO_UNDERLINE         DEBUG_SINGLE_C(24)
#define DEBUG_NO_OVERLINED         DEBUG_SINGLE_C(55)

#define DEBUG_BOLD                 DEBUG_SINGLE_C( 1)
#define DEBUG_FAINT                DEBUG_SINGLE_C( 2)
#define DEBUG_ITALIC               DEBUG_SINGLE_C( 3)
#define DEBUG_UNDERLINE            DEBUG_SINGLE_C( 4)
#define DEBUG_OVERLINED            DEBUG_SINGLE_C(53)
#define DEBUG_SLOW_BLINK           DEBUG_SINGLE_C( 5)
#define DEBUG_REVERSE              DEBUG_SINGLE_C( 7)
#define DEBUG_STRIKE               DEBUG_SINGLE_C( 9)

#define DEBUG_8BIT_FOREGROUND(c)   "\033[38;5;" + (c) + "m"
#define DEBUG_DEFAULT_FOREGROUND   DEBUG_SINGLE_C(39)

#define DEBUG_FG_BLACK             DEBUG_SINGLE_C(30)
#define DEBUG_FG_RED               DEBUG_SINGLE_C(31)
#define DEBUG_FG_GREEN             DEBUG_SINGLE_C(32)
#define DEBUG_FG_YELLOW            DEBUG_SINGLE_C(33)
#define DEBUG_FG_BLUE              DEBUG_SINGLE_C(34)
#define DEBUG_FG_MAGENTA           DEBUG_SINGLE_C(35)
#define DEBUG_FG_CYAN              DEBUG_SINGLE_C(36)
#define DEBUG_FG_WHITE             DEBUG_SINGLE_C(37)

#define DEBUG_8BIT_BACKGROUND(c)   "\033[48;5;" + (c) + "m"
#define DEBUG_DEFAULT_BACKGROUND   DEBUG_SINGLE_C(49)

#define DEBUG_BG_BLACK             DEBUG_SINGLE_C(40)
#define DEBUG_BG_RED               DEBUG_SINGLE_C(41)
#define DEBUG_BG_GREEN             DEBUG_SINGLE_C(42)
#define DEBUG_BG_YELLOW            DEBUG_SINGLE_C(43)
#define DEBUG_BG_BLUE              DEBUG_SINGLE_C(44)
#define DEBUG_BG_MAGENTA           DEBUG_SINGLE_C(45)
#define DEBUG_BG_CYAN              DEBUG_SINGLE_C(46)
#define DEBUG_BG_WHITE             DEBUG_SINGLE_C(47)

#define DEBUG_FORMAT(str,len) (((str.length()-len)<0)? \
                               (str) : ( "..." +  str.substr(str.length() - len) ) )
        
#define DEB_WARS(str) { \
      std::cout  << DEBUG_RESET << DEBUG_BOLD << DEBUG_COLOR_BG_RGB(250,204,000)<< \
      DEBUG_COLOR_FG_RGB(000,000,000)<< "[WAR] "<< std::left << std::setw(10)<<\
      SCOPE_NAME << ": " << DEBUG_NORMALIZE << std::left << std::setw(MSG_LEN) << str << \
      " @"<< std::right << std::setw(5) << __LINE__ <<" ~ "<< \
      DEBUG_FORMAT(_S(__FILE__),PAT_LEN) << _PT() << DEBUG_RESET <<  std::endl; }        


#define DEB_ERRS(str) { \
      std::cout  << DEBUG_RESET << DEBUG_BOLD << DEBUG_COLOR_BG_RGB(204,000,000)<< \
      DEBUG_COLOR_FG_RGB(255,254,255)<< "[ERR] "<< std::left << std::setw(10)<<\
      SCOPE_NAME << ": "  << std::left << std::setw(MSG_LEN) << str << DEBUG_NORMALIZE <<\
      " @"<< std::right << std::setw(5) << __LINE__ <<" ~ "<< \
      DEBUG_FORMAT(_S(__FILE__),PAT_LEN) << _PT() << DEBUG_RESET <<  std::endl; }
        
        
#define DEB_MSG_PS(str) { \
    std::cout  << DEBUG_RESET << DEBUG_BOLD << DEBUG_COLOR_BG_RGB(210,255,210)<< \
    DEBUG_COLOR_FG_RGB(000,000,000)<< "[UNT] "<< std::left << std::setw(10)<<\
    SCOPE_NAME << ": PASSED " << DEBUG_NORMALIZE << std::left << std::setw(MSG_LEN - 7) << str << \
    " @"<< std::right << std::setw(5) << __LINE__ <<" ~ "<< \
    DEBUG_FORMAT(_S(__FILE__),PAT_LEN) << _PT() << DEBUG_RESET <<  std::endl; }
        
#if YELLOWDEBUG >  0
    #define DEB_MSG_1S(str) { \
      std::cout  << DEBUG_RESET << DEBUG_BOLD << DEBUG_COLOR_BG_RGB(240,255,240)<< \
      DEBUG_COLOR_FG_RGB(000,000,000)<< "[DL1] "<< std::left << std::setw(10)<<\
      SCOPE_NAME << ": " << DEBUG_NORMALIZE << std::left << std::setw(MSG_LEN) << str << \
      " @"<< std::right << std::setw(5) << __LINE__ <<" ~ "<< \
      DEBUG_FORMAT(_S(__FILE__),PAT_LEN) << _PT() << DEBUG_RESET <<  std::endl; }
#else
    #define DEB_MSG_1(str);
    #define DEB_MSG_1(str);
#endif
#if YELLOWDEBUG > 1
    #define DEB_MSG_2S(str) { \
      std::cout  << DEBUG_RESET << DEBUG_BOLD << DEBUG_COLOR_BG_RGB(240,220,240)<< \
      DEBUG_COLOR_FG_RGB(000,000,000)<< "[DL2] "<< std::left << std::setw(10)<<\
      SCOPE_NAME << ": " << DEBUG_NORMALIZE << std::left << std::setw(MSG_LEN) << str << \
      " @"<< std::right << std::setw(5) << __LINE__ <<" ~ "<< \
      DEBUG_FORMAT(_S(__FILE__),PAT_LEN) << _PT() << DEBUG_RESET <<  std::endl; }
#else
    #define DEB_MSG_2S(str);
#endif
#if YELLOWDEBUG > 2 
    #define DEB_MSG_3S(str) { \
      std::cout  << DEBUG_RESET << DEBUG_BOLD << DEBUG_COLOR_BG_RGB(230,230,230)<< \
      DEBUG_COLOR_FG_RGB(000,000,000)<< "[DL3] "<< std::left << std::setw(10)<<\
      SCOPE_NAME << ": " << DEBUG_NORMALIZE << std::left << std::setw(MSG_LEN) << str << \
      " @"<< std::right << std::setw(5) << __LINE__ <<" ~ "<< \
      DEBUG_FORMAT(_S(__FILE__),PAT_LEN) << _PT() << DEBUG_RESET <<  std::endl; }
#else
    #define DEB_MSG_3S(str);
#endif

#if YELLOWDEBUG > 3 
    #define DEB_MSG_CS(str) { \
      std::cout  << DEBUG_RESET << DEBUG_BOLD << \
      DEBUG_COLOR_BG_RGB(188,205,209)<< \
      DEBUG_COLOR_FG_RGB(000,000,000)<< "[CAL] "<< std::left << std::setw(10)<<\
      SCOPE_NAME << ": CALLED " << DEBUG_NORMALIZE << std::left << std::setw(MSG_LEN -7) \
      << str << \
      " @"<< std::right << std::setw(5) << __LINE__ <<" ~ "<< \
      DEBUG_FORMAT(_S(__FILE__),PAT_LEN) << _PT() << DEBUG_RESET <<  std::endl; }
#else
    #define DEB_MSG_CS(str);
#endif

#define DEB_WAR(str) DEB_WARS(str)
#define DEB_ERR(str) DEB_ERRS(str)

#define DEB_MSG_C(str) DEB_MSG_CS(str)

#define DEB_MSG_3(str) DEB_MSG_3S(str)
#define DEB_MSG_2(str) DEB_MSG_2S(str)
#define DEB_MSG_1(str) DEB_MSG_1S(str)


#if SCOPE_NAME == 0
     #undef SCOPE_NAME
#endif



#endif
*/

#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <string>
#include <iostream>

#define _S(s)                      std::string(s)
#define _T(s)                      std::to_string(s)

#define DEBUG_ESCAPE               _S("\033[")
#define DEBUG_SINGLE_C(c)          (DEBUG_ESCAPE+_T(c)+"m")

#define DEBUG_COLOR_FG_RGB(r,g,b)  (DEBUG_ESCAPE+_S("38;2;")+_T(r)+_S(";")+ \
                                    _T(g)+_S(";")+_T(b)+_S("m"))
#define DEBUG_COLOR_BG_RGB(r,g,b)  (DEBUG_ESCAPE+_S("48;2;")+_T(r)+_S(";")+ \
                                    _T(g)+_S(";")+_T(b)+_S("m"))

#define DEBUG_RESET                DEBUG_SINGLE_C( 0)

#define DEBUG_NORMALIZE            DEBUG_SINGLE_C(22)
#define DEBUG_NORMALIZE_2          DEBUG_SINGLE_C(23)
#define DEBUG_NO_UNDERLINE         DEBUG_SINGLE_C(24)
#define DEBUG_NO_OVERLINED         DEBUG_SINGLE_C(55)

#define DEBUG_BOLD                 DEBUG_SINGLE_C( 1)
#define DEBUG_FAINT                DEBUG_SINGLE_C( 2)
#define DEBUG_ITALIC               DEBUG_SINGLE_C( 3)
#define DEBUG_UNDERLINE            DEBUG_SINGLE_C( 4)
#define DEBUG_OVERLINED            DEBUG_SINGLE_C(53)
#define DEBUG_SLOW_BLINK           DEBUG_SINGLE_C( 5)
#define DEBUG_REVERSE              DEBUG_SINGLE_C( 7)
#define DEBUG_STRIKE               DEBUG_SINGLE_C( 9)

#define DEBUG_8BIT_FOREGROUND(c)   "\033[38;5;" + (c) + "m"
#define DEBUG_DEFAULT_FOREGROUND   DEBUG_SINGLE_C(39)

#define DEBUG_FG_BLACK             DEBUG_SINGLE_C(30)
#define DEBUG_FG_RED               DEBUG_SINGLE_C(31)
#define DEBUG_FG_GREEN             DEBUG_SINGLE_C(32)
#define DEBUG_FG_YELLOW            DEBUG_SINGLE_C(33)
#define DEBUG_FG_BLUE              DEBUG_SINGLE_C(34)
#define DEBUG_FG_MAGENTA           DEBUG_SINGLE_C(35)
#define DEBUG_FG_CYAN              DEBUG_SINGLE_C(36)
#define DEBUG_FG_WHITE             DEBUG_SINGLE_C(37)

#define DEBUG_8BIT_BACKGROUND(c)   "\033[48;5;" + (c) + "m"
#define DEBUG_DEFAULT_BACKGROUND   DEBUG_SINGLE_C(49)

#define DEBUG_BG_BLACK             DEBUG_SINGLE_C(40)
#define DEBUG_BG_RED               DEBUG_SINGLE_C(41)
#define DEBUG_BG_GREEN             DEBUG_SINGLE_C(42)
#define DEBUG_BG_YELLOW            DEBUG_SINGLE_C(43)
#define DEBUG_BG_BLUE              DEBUG_SINGLE_C(44)
#define DEBUG_BG_MAGENTA           DEBUG_SINGLE_C(45)
#define DEBUG_BG_CYAN              DEBUG_SINGLE_C(46)
#define DEBUG_BG_WHITE             DEBUG_SINGLE_C(47)


#ifndef YELLOWDEBUG
  #define YELLOWDEBUG 0
#endif
#ifndef PROJECT_NAME
  #define PROJECT_NAME "undefined"
#endif
#ifndef PROJECT_VERSION
  #define PROJECT_VERSION 0
#endif

#define VALUETOSTRING(x) #x
#define VALUE(x) VALUETOSTRING(x)
#define PERFORMPRAGMA(str) _Pragma(#str)
#if YELLOWDEBUG >= 0
  #define DEB_WAR(str) {\
        std::cout << DEBUG_RESET << DEBUG_COLOR_BG_RGB(255,204,000) << \
        DEBUG_COLOR_FG_RGB(000,000,000) << "[WAR] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << DEBUG_RESET;}
  #define DEB_ERR(str) {\
        std::cout << DEBUG_RESET << DEBUG_COLOR_BG_RGB(204,000,000) << \
        DEBUG_COLOR_FG_RGB(255,254,255) << std::endl << "[ERR] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << std::endl << DEBUG_RESET;}
#else
  #define DEB_WAR(str);
  #define DEB_ERR(str);
#endif
#if YELLOWDEBUG > 0
  #pragma message ("your compiling " VALUE(PROJECT_NAME) " version: " VALUE(PROJECT_VERSION))
  #define P_DEB_MSG(str) PERFORMPRAGMA(message ("" #str))
  #define P_MAC_MSG(mac,str) PERFORMPRAGMA(message("you have set: " #mac " to " VALUE(mac) " - " #str))
  #define DEB_MSG_1(str) {\
        std::cout << DEBUG_RESET << DEBUG_COLOR_BG_RGB(240,255,240) << \
        DEBUG_COLOR_FG_RGB(000,000,000) << "[DL1] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << DEBUG_RESET;}
#else
  #define P_DEB_MSG(str);
  #define P_MAC_MSG(mac,str);
  #define DEB_MSG_1(str);
#endif

#if YELLOWDEBUG > 1
  #define DEB_MSG_2(str) {\
        std::cout << DEBUG_RESET << DEBUG_COLOR_BG_RGB(240,220,240) << \
        DEBUG_COLOR_FG_RGB(000,000,000) << "[DL2] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << DEBUG_RESET;}
#else
  #define DEB_MSG_2(str);
#endif

#if YELLOWDEBUG > 2
  #define DEB_MSG_3(str) {\
        std::cout << DEBUG_RESET << DEBUG_COLOR_BG_RGB(240,200,240) << \
        DEBUG_COLOR_FG_RGB(000,000,000) << "[DL3] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << DEBUG_RESET;}
#else
  #define DEB_MSG_3(str);
#endif

#endif
