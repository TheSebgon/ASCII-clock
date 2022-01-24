#pragma once

#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <string>


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