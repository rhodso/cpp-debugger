// Source file auto-generated using CPP-Getter-Setter-Generator

// Includes
#include "dbg.h"

// Inital values
bool dbg::enabled{false};  // Set enabled false by default
std::time_t dbg::initTime{std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())}; // Program Init time

// Constructor and Destructor
dbg::dbg(){
    enabled = false;
}
dbg::dbg(bool _enabled){
    enabled = _enabled;
}
dbg::~dbg(){}

// Getters and Setters
std::time_t dbg::getInitTime(){ return initTime; }
bool dbg::getEnabled(){ return enabled; }

void dbg::setInitTime( std::time_t _initTime){ initTime = _initTime; }
void dbg::setEnabled( bool _enabled){ enabled = _enabled; }

// Logging and printing methods
/*
    Logging is printing with execution time
    Printing doesn't have execution time
*/
void dbg::log(std::string _msg){
    // Only print if enabled
    if(enabled){
        logIgnore(_msg);
    }
}
void dbg::logIgnore(std::string _msg){
    // Log regardless of if enabled or nah
    std::cout << getExecTime_SF() + "\t" + _msg << std::endl;
}
// Various shorhand logging methods for different purposes
void dbg::logWrn(std::string _msg){ std::cerr << "\033[1;33m" << getExecTime_SF() + "\t" + _msg << "\033[0m" << std::endl; }
void dbg::logErr(std::string _msg){ std::cerr << "\033[1;31m" << getExecTime_SF() + "\t" + _msg << "\033[0m" << std::endl; }
void dbg::logClr(std::string _msg){ logClr(_msg, 2); }

// Log thing in colour
void dbg::logClr(std::string _msg, int _clr){
    // See enum in header file for colours
    if(_clr > 7 || _clr < 0){
        // In case someone tries to use a colour that's not supposed
        logErr("Unsupported colour used for message: \n\"" + _msg + "\"");
    } else {
        // Log in specified colour
        std::cout << "\033[1;3" + std::to_string(_clr) + "m" << _msg << "\033[0m" << std::endl;
    }

}
// Rainbow logging commands
void dbg::logRnbw(std::string _msg){
    _msg = getExecTime_SF() + _msg;
    int colours[] = {1, 3, 2, 4, 5};
    int i = 0;
    for(char& c : _msg) {
        i = i % 5;
        std::cout << "\033[1;3" + std::to_string(colours[i]) + "m" << c << "\033[0m";
        i++;
    }
    std::cout << std::endl;

}
void dbg::pRnbw(std::string _msg){
        int colours[] = {1, 3, 2, 4, 5};
    int i = 0;
    for(char& c : _msg) {
        i = i % 5;
        std::cout << "\033[1;3" + std::to_string(colours[i]) + "m" << c << "\033[0m";
        i++;
    }
    std::cout << std::endl;

}
// Shorthands
void dbg::l(std::string _msg){ dbg::log(_msg); } // Shorthand for standard log
void dbg::p(std::string _msg){ dbg::print(_msg); } // Shorthand for print

// Standard print command
void dbg::print(std::string _msg){ std::cout << _msg << std::endl; }

// Execution time methods
std::string dbg::getExecTime_S(){ return std::to_string(getExecTime()); }
std::string dbg::getExecTime_SF(){ return "[" + getExecTime_S() + "]"; }
double dbg::getExecTime(){
    // Get the time and return it as a double
    return std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::system_clock::now() -
                            std::chrono::system_clock::from_time_t(initTime))
                            .count() /
                            1000.0f;
}
