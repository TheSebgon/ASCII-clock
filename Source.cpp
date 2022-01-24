#include "Header.h"


namespace ASCII_art		//ASCII art digits + colon
{
	std::string ASCII[11][5]{
{ " @@@@","@@  @@","@@  @@","@@  @@"," @@@@" },
{ " @@@  ","@ @@  ","  @@  ","  @@  ","@@@@@@", },	//1
{ " @@@@ ", "@@  @@", "   @@ ", "  @@  ", "@@@@@@"},
{ " @@@@ ","@@  @@","   @@@","@@  @@"," @@@@ " },	//3
{ "@@  @@","@@  @@","@@@@@@","    @@","    @@" },
{ "@@@@@@","@@    ","@@@@@ ","    @@","@@@@@ " },	//5
{ " @@@@ ","@@    ","@@@@@ ","@@  @@"," @@@@ " },
{ "@@@@@@","   @@ ","  @@  "," @@   ","@@    " },	//7
{ " @@@@ ","@@  @@"," @@@@ ","@@  @@"," @@@@ "},
{ " @@@@ ","@@  @@"," @@@@@","    @@"," @@@@ " },	//9
{ "     ","  @  ","     ","  @  ","     " }			//Colon
	};
};

Time::Time(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

void Time::update_Time()		//catch system time
{
	time_t now = time(NULL);
	char str[26] = {};
	ctime_s(str, 26, &now);

	char temp[2];
	temp[0] = str[11];
	temp[1] = str[12];
	hours = atoi(temp);

	temp[0] = str[14];
	temp[1] = str[15];
	minutes = atoi(temp);

	temp[0] = str[17];
	temp[1] = str[18];
	seconds = atoi(temp);
}
void Time::print_Time()		//print time as ASCII art
{
	using namespace ASCII_art;

	for (int i = 0; i < 5; i++)
	{
		std::cout << ASCII[hours / 10][i] << "\t";	//hours
		std::cout << ASCII[hours % 10][i] << "\t";

		std::cout << ASCII[10][i] << "\t";			//colon

		std::cout << ASCII[minutes / 10][i] << "\t";	//minutes
		std::cout << ASCII[minutes % 10][i] << "\t";

		std::cout << ASCII[10][i] << "\t";			//colon

		std::cout << ASCII[seconds / 10][i] << "\t";	//seconds
		std::cout << ASCII[seconds % 10][i] << "\n";
	}
}