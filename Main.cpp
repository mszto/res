#include "Gra.h"
#include "Menu.h"
#include <iostream>


using namespace std;

int main()
{
	srand(time(NULL));
	Menu menu;
	Gra game;
//	Player *gr = new Player();
	for (;;)
	{
		int wybor=1,i=0;
		
		wybor = menu.wyswietl();
		
		switch (wybor)
		{

		case 1:
			i = menu.gracz_cpu();
			game.start(i);
			break;

		case 2:
			menu.najlepszy_wynik();
			break;

		case 3:
			menu.wyjscie();
			break;
		}

	}
	return 0;
}
/*		switch (wybor)
		{
			
		case 1:
			 i = menu.gracz_cpu();
			game.start(i);
			break;

		case 2:
			menu.najlepszy_wynik();
			break;

		case 3:
			menu.wyjscie();
			break;
		}*/

