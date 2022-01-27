#include "Header.h"

//Menu
/////////////////////////////////////////////////////////////
void show_main_menu()
{
	Time t1;
	while (1)
	{
		t1.update_time();
		t1.print_time();

		std::cout << "\nOptions:\n"
			<< "a) Set sign used for displaying	\t"
			<< "b) Real time clock\n"
			<< "c) Time calculator\t\t\t"
			<< "q) Exit program\n";

		char option;
		std::cin >> option;

		if (isalpha(option))			//Check if good input and swap to lower letter
			int tolower(option);
		else
		{
			system("cls");
			std::cout << "Invalid input, please use options below\n\n";
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
		case 'c':
			system("cls");
			show_calc_menu();  break;
		case 'q':
			exit(0);
		default:						//Wrong option
			system("cls");
			std::cout << "Invalid option, please select the correct one.\n\n";
			break;
		}
	}
}

void show_ascii_menu()	//ASCII manip menu
{
	screen_transmision("Display options...");

	while (1)
	{
		display_mode(200);

		std::cout << "Options\n"
			<< "a) Choose ASCII character\t"
			<< "b) Set random ASCII character\n"
			<< "q) Back to main menu\n";
		char option;
		std::cin >> option;

		if (isalpha(option))			//Check if good input and swap to lower letter
			int tolower(option);
		else
		{
			system("cls");
			std::cout << "Invalid input, please use options below\n\n";
			continue;
		}
		if (option == 'q')		//Back to main menu
		{
			system("cls");
			break;
		}

		switch (option)
		{
		case 'a':					//Ask for ASCII sign
			system("cls");
			display_mode(0);
			std::cout << "Choose any ASCII sign: ";
			char sign;
			std::cin >> sign;
			change_ASCII(sign);
			continue;
		case'b':					//Random character
			system("cls");
			display_mode(0);
			srand(static_cast<unsigned int>(time(NULL)));
			change_ASCII(rand() % (127 - (-128) + 1) + (-128));		//Rand in ASCII range
			break;
		default:
			system("cls");
			std::cout << "Invalid option, please select the correct one.\n\n";
			continue;
		}
	}
}

void show_calc_menu()
{
	Time t1, t2, temp;
	screen_transmision("Time calculator...");

	while (1)
	{
		std::cout << "BASE TIME: \n\n";

		t1.print_time(0);


		std::cout << "\n\nOptions\n"
			<< "a) Change base time\t"
			<< "b) Use current time\n"
			<< "c) Add time to the base\t"
			<< "d) Subtract time from the base\n"
			<< "q) Back to main menu\n";

		char option;
		std::cin >> option;

		if (isalpha(option))			//Check if good input and swap to lower letter
			int tolower(option);
		else
		{
			system("cls");
			std::cout << "Invalid input, please use options below\n\n";
			continue;
		}
		if (option == 'q')		//Back to main menu
		{
			system("cls");
			break;
		}

		switch (option)
		{
		case 'a':
			system("cls");
			std::cout << std::endl;
			get_time(t1);
			break;
		case 'b':
			system("cls");
			t1.update_time();
			break;
		case 'c':
			system("cls");
			std::cout << "\nHow much time do you want to add?\n";
			get_calc_time(t2);
			system("cls");
			temp = t1 + t2;
			t1 = temp;
			break;
		case 'd':
			system("cls");
			std::cout << "\nHow much time do you want to subtract ?\n";
			get_calc_time(t2);
			system("cls");
			temp = t1 - t2;	
			t1 = temp;
			break;
		default:
			system("cls");
			std::cout << "Invalid option, please select the correct one.\n\n";
			continue;
		}
	}
}

void screen_transmision(std::string s)		//Transmission for screens
{
	for (int i = 0; i < s.length(); i++)
		std::cout << s[i]; Sleep(75);

	Sleep(500);
	system("cls");
}