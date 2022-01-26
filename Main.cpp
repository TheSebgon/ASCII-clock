#include "Header.h"

int main()
{	
	std::string options = "ASCII ART TIME APP...";

	for (int i = 0; i < options.length(); i++)
	{
		std::cout << options[i]; Sleep(100);
	}
	Sleep(500);
	system("cls");

	show_main_menu();
	
}

// add another ascii MODE maybe so change display mode also
//add time calulator (overl op) + menu for calc
//also maybe consider  new version of change_ASCII() with menu ( ..... how quit withou losing one sign); 