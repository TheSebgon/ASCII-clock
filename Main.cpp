#include "Header.h"

int main()
{
	Time czas1;
	while (1)
	{
		czas1.update_Time();
		czas1.print_Time();
		Sleep(1000);
		system("cls");
	}
}
