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
{ "     ","  @  ","     ","  @  ","     " },			//Colon
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

void Time::update_time()		//Catch system time
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
void Time::print_time(bool s)		//Print time as ASCII art
{
	using  ASCII_art::ASCII;

	for (int i = 0; i < 5; i++)
	{
		std::cout << ASCII[hours / 10][i] << "\t";		//hours
		std::cout << ASCII[hours % 10][i] << "\t";

		std::cout << ASCII[10][i] << "\t";				//colon

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

void Time::set_time(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::operator+(const Time& t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	sum.hours %= 24;
	return sum;
}

Time Time::operator-(const Time& t)const
{
	int th = t.hours, tm = t.minutes;
	Time diff;
	diff.minutes = minutes;
	diff.hours = hours;

	if (tm > diff.minutes)
	{
		th++;
		diff.minutes += 60;
	}

	diff.minutes -= tm;

	while (th > diff.hours)
		diff.hours += 24;
	
	diff.hours -= th;
	return diff;
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

void change_ASCII(char sign)	// ASCII character change					
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

void display_mode(int sleep)			//Display current mode
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

// Other
//////////////////////

void show_clock()		//Real time clock
{
	system("cls");
	Time x;
	for (int i=5;i>=0;i--)
	{
		x.update_time();
		x.print_time();
		std::cout << "\n\nBack to main menu in: " << i<<" seconds";
		Sleep(1000);
		system("cls");
	}
}

void get_time(Time& t)		//Ask user about base time
{
	int h, m;

	while (true)
	{
		std::cout << "\nHours: ";
		std::cin >> h;

		if ((std::cin) && (h > 0) && (h < 24)) break;

		std::cin.clear();
		std::cin.ignore(1000, '\n');
		system("cls");
		std::cout << "Invalid time input, please input hours in range 0-23\n " << std::flush;
	}
	system("cls");

	while (true)
	{
		std::cout << "\nMinutes: ";
		std::cin >> m;

		if ((std::cin) && (m > 0) && (m < 60)) break;

		std::cin.clear();
		std::cin.ignore(1000, '\n');
		system("cls");
		std::cout << "Invalid time input, please input hours in range 0-59\n " << std::flush;
	}
	system("cls");
	t.set_time(h, m);
}

void get_calc_time(Time& t)		//Ask user about calculation time
{
	int h, m;

	while (true)
	{
		std::cout << "\nHours: ";
		std::cin >> h;

		if (std::cin) break;

		std::cin.clear();
		std::cin.ignore(1000, '\n');
		system("cls");
		std::cout << "Invalid time input, use digits \n " << std::flush;
	}
	system("cls");

	while (true)
	{
		std::cout << "\nMinutes: ";
		std::cin >> m;

		if (std::cin) break;

		std::cin.clear();
		std::cin.ignore(1000, '\n');
		system("cls");
		std::cout << "Invalid time input, use digits\n " << std::flush;
	}
	system("cls");
	t.set_time(h, m);
}