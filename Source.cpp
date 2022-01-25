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
	using  ASCII_art::ASCII;

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

void change_ASCII()									
{
	using ASCII_art::ASCII;
	display_mode();
	Sleep(1000);
	std::cout << "Choose any ASCII sign: ";
	char y;
	std::cin >> y;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 5; j++)
			replace_sign(ASCII[i][j], y);
	}
	system("cls");
}

void show_clock()
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

void display_mode()
{
	using ASCII_art::ASCII;
	std::cout << "\t Current display mode:\n";
	for (int i = 0; i < 5; i++)
	{
		std::cout <<"\t\t"<< ASCII[0][i] << "\n";
	}
	std::cout << std::endl;
}


void show_menu()
{
	while (1)
	{
		Sleep(500);
		std::cout <<"Options:\n"
			<< "a) Set sign used for displaying	\t"
			<< "b) Real time clock\n";

		char option;
		std::cin >> option;

		if (isalpha(option))			//Check if good input and swap to lower letter
			int tolower(option);
		else
		{
			system("cls");
			std::cout << "Invalid input, please use letter from options below\n\n";
			continue;
		}

		switch (option)					//Selected option 
		{
		case 'a':						//ASCII sign choose
			system("cls"); 
			change_ASCII();
			std::cout << "\t Display ASCII changed:\n";
			display_mode();
			Sleep(500); break;
		case 'b':						//Real time clock
			system("cls"); 
			show_clock();  break;
		default:						//Wrong option
			system("cls");
			std::cout << "Invalid option, please choose correct one.\n\n"; 
			break;
		}
	}
}