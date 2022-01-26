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

//Real time clock
//////////////////////////
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

//menu
/////////////////////////////////////////////////////////////
void show_main_menu()
{
	while (1)
	{
		display_mode(0);
		std::cout << "Options:\n"
			<< "a) Set sign used for displaying	\t"
			<< "b) Real time clock\n"
			<< "q) Exit program\t\n";

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
			show_ascii_menu(); break;
		case 'b':						//Real time clock
			system("cls"); 
			show_clock();  break;
		case 'q':
			exit(0);
		default:						//Wrong option
			system("cls");
			std::cout << "Invalid option, please choose correct one.\n\n"; 
			break;
		}
	}
}

void show_ascii_menu()
{
	while (1)
	{
		display_mode(200);

		std::cout << "Options\n"
			<< "a) Choose ASCII sign\t"
			<< "b) Set random ASCII sign\n"
			<< "q) Back to main menu\n";
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
		if (option == 'q')		//back to main menu
		{
			system("cls");
			break;
		}

		switch (option)
		{
		case 'a':					//ask for ASCII sign
			system("cls");
			display_mode(0);
			std::cout << "Choose any ASCII sign: ";
			char sign;
			std::cin >> sign;
			change_ASCII(sign);
			continue;
		case'b':					//Random sign
			system("cls");
			display_mode(0);
			srand(time(NULL));
			change_ASCII(rand() % (127 - (-128) + 1) + (-128));		//rand in ASCII range
			break;
		default:
			system("cls");
			std::cout << "Invalid option, please choose correct one.\n\n";
			continue;
		}
	}
}