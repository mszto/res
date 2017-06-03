#include "Gracze.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>




class Gra{
	int const rozmiar_planszy;
	char pole_gry[16][16];
	Players *gracz;
	int gracze[4];
	void losuj_kolejnosc(int ile);
	friend int sprawdz_wygrana(const Gra *g, Players *p);
public:
	Gra();
	void start(int ile_cpu);
	
};



