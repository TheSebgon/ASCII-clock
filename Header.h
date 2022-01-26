#pragma once

#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <ctype.h>


class Time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time(int h = 00, int m = 00, int s = 00);
	void update_Time();							//catch system time
	void print_Time(bool s = 1);				//print time as ASCII art
	void set_time();
	Time operator+(const Time& t) const;
};


//functions
//////////////////////////////////////

//ASCII manip
void replace_sign(std::string& str, char c2);
void change_ASCII( char sign);	// ASCII sign change
void display_mode(int sleep);	//displaying current mode

//Clock
void show_clock();		//Print clock based on system time

//Menu
void show_main_menu();		//main menu of app
void show_ascii_menu();		//ASCII display menu
void show_calc_menu();		//Time calculator menu