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

//class
/// ///////////////////////////////////////////////

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
void Time::print_Time(bool s)		//print time as ASCII art
{
	using  ASCII_art::ASCII;

	for (int i = 0; i < 5; i++)
	{
		std::cout << ASCII[hours / 10][i] << "\t";	//hours
		std::cout << ASCII[hours % 10][i] << "\t";

		std::cout << ASCII[10][i] << "\t";			//colon

		std::cout << ASCII[minutes / 10][i] << "\t";	//minutes
		std::cout << ASCII[minutes % 10][i] << "\t";

		if (s == 1)
		{
			std::cout << ASCII[10][i] << "\t";			//colon

			std::cout << ASCII[seconds / 10][i] << "\t";	//seconds
			std::cout << ASCII[seconds % 10][i] << "\n";
		}
		else
			std::cout << std::endl;
	}
}
void Time::set_time()
{
	int temp;
	std::cout << "Hours: ";
	std::cin >> temp;
	hours = temp;
	
	std::cout << "\nMinutes: ";
	std::cin >> temp;
	minutes = temp;

	system("cls");
}

Time Time::operator+(const Time& t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time& t)const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot1 - tot1) % 60;
	diff.hours = (tot1 - tot2) / 60;
	return diff;
}

Time Time::operator*(double mult)const
{
	Time result;
	long totalminutes = hours * mult * 60 + minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

//ASCII manip
///////////////////////////////////////////////////

void replace_sign(std::string& str, char c2)
{
	unsigned int i = 0;
	while (i < str.length())
	{
		if (str[i] != ' ')     str[i] = c2;
		i++;
	}
}

void change_ASCII(char sign)									
{
	using ASCII_art::ASCII;
	Sleep(500);
	
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 5; j++)
			replace_sign(ASCII[i][j], sign);
	}
	system("cls");
}

void display_mode(int sleep)			//displaying current mode
{
	using ASCII_art::ASCII;
	std::cout << "\t Current display mode:\n\n";
	for (int i = 0; i < 5; i++)
	{
		std::cout <<"\t\t"<< ASCII[0][i] << "\n";
		Sleep(sleep);
	}
	std::cout << std::endl;
}

void show_clock()		//Real time clock
{
	system("cls");
	Time x;
	for (;;)
	{
		x.update_Time();
		x.print_Time();
		Sleep(1000);
		system("cls");
	}
}