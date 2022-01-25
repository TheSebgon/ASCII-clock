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
	void print_Time();							//print time as ASCII art
};


//functions
void replace_sign(std::string& str, char c2);
void change_ASCII();	//ask for ASCII sign
void show_clock();		
void show_menu();		//main menu of app
void display_mode();	//displaying current mode