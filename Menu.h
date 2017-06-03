#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

struct wyniki
{
	int wynik;
	string gracz;
};


class Menu
{
	int const enter = 13;
	int const up = 80;
	int const down = 72;

	wyniki tab_wynikow[5];
	void logo();

public:

	void wczytaj_wyniki();
	int wyswietl();
	void najlepszy_wynik();
	void nowa_gra();
	void wyjscie();
	int gracz_cpu();

};