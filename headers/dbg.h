//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef D_H
#define D_H

//Includes
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <thread>
#include <string.h>
#include <chrono>
#include <iostream>


class dbg {
	public:
		//Constructor and Destructor
		dbg();
		dbg(bool _enabled);
		~dbg();

		//Getters and Setters
		static std::time_t getInitTime();
		static bool getEnabled();

		static void setInitTime( std::time_t _initTime );
		static void setEnabled( bool _enabled );

		//Other methods
		static void log(std::string _msg);
		static void logWrn(std::string _msg);
		static void logErr(std::string _msg);
		static void logIgnore(std::string _msg);
		static void logClr(std::string _msg);
		static void logClr(std::string _msg, int _clr);
		static void p(std::string _msg);
		static void print(std::string _msg);
		static double getExecTime();
		static std::string getExecTime_S();
		static std::string getExecTime_SF();

		enum colourCode{
			BLACK = 0,
			RED = 1,
			GREEN = 2, 
			YELLOW = 3,
			BLUE = 4,
			MAGENTA = 5,
			CYAN = 6,
			WHITE = 7
		};

	private:
		//Variables
		static std::time_t initTime;
		static bool enabled;

};
#endif