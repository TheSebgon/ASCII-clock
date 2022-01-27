#pragma once

#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include <thread>


class Time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time(int h = 00, int m = 00, int s = 00);
	void update_time();							//Catch system time
	void print_time(bool s = 1);				//Print time as ASCII art
	void set_time(int h, int m);				//Set time 
	Time operator+(const Time& t) const;
	Time operator-(const Time& t) const;
};

//Functions
//////////////////////////////////////

//ASCII manip
void replace_sign(std::string& str, char c2);	//Character swap
void change_ASCII( char sign);	//ASCII character change
void display_mode(int sleep);	//Displaying current mode

//Clock
void show_clock();				//Print clock based on system time
void get_time(Time& t);			//Ask user about base time
void get_calc_time(Time& t);	//Ask user about calculation time

//Menu
void show_main_menu();					//Main menu of app
void show_ascii_menu();					//ASCII display menu
void show_calc_menu();					//Time calculator menu
void screen_transmision(std::string s);	//Transmission for screens
