#include "Header.h"

//menu
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
		case 'c':
			system("cls");
			show_calc_menu();  break;
		case 'q':
			exit(0);
		default:						//Wrong option
			system("cls");
			std::cout << "Invalid option, please choose correct one.\n\n";
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
			srand(static_cast<unsigned int>(time(NULL)));
			change_ASCII(rand() % (127 - (-128) + 1) + (-128));		//rand in ASCII range
			break;
		default:
			system("cls");
			std::cout << "Invalid option, please choose correct one.\n\n";
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
		std::cout << "TIME: \n\n";

		t1.print_time(0);


		std::cout << "\n\nOptions\n"
			<< "a) Change base time\n"
			<< "b) Use current time\n"
			<< "c) Adding time (Time after x time) \n"
			<< "d) Subtraction time (Which time was x time ago)\n"
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
		case 'a':
			system("cls");
			std::cout << std::endl;
			t1.set_time();
			break;
		case 'b':
			system("cls");
			t1.update_time();
			break;
		case 'c':
			system("cls");
			std::cout << "\nHow much time is to pass ?\n";
			t2.set_time();
			system("cls");
			temp = t1 + t2;
			t1 = temp;
			break;
		case 'd':
			system("cls");
			std::cout << "\nHow much time do you want to subtract ?\n";
			t2.set_time();
			system("cls");
			temp = t1 - t2;	
			t1 = temp;
			break;
		default:
			system("cls");
			std::cout << "Invalid option, please choose correct one.\n\n";
			continue;
		}
	}
}

void screen_transmision(std::string s)
{
	for (signed int i = 0; i < s.length(); i++)
	{
		std::cout << s[i]; Sleep(75);
	}
	Sleep(500);
	system("cls");
}