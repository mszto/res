#include <windows.h>
#include "List.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;
#define _INCLUDE_LIST_H

 // klasa bazowa
class Players{
	char pionki[4];
protected:
	const int  rozmaiar_planszy;
	Lista_ruchow *lista;

	void lista_ruchow_stworz(int x, int y, char plansza[16][16]);
	void lista_ruchow_po_skoku_stworz(int x, int y,int x2, int y2, char plansza[16][16]);
	bool sprawdz_skok(int x, int y,int x2,int y2,char plansza[16][16]);
	void naglowek(int gracz);
	bool rysuj(int x, int y);
public:

	Players();

	 char getPionki(int i);
	
	 virtual int wykonaj_ruch(char pole_gry[16][16], int pionek);
};


// klasa odpowiedzialana za wykonywanie ruchow czlowieka dziedziczy po klasie Players
class Player
	:public Players{
	const int  enter;
	const int  up;
	const int  down;
	const int right;
	const int left;
	//char pole_gry[16][16];
	char pozycja;
	int x, y;

	// zwraca 1- gdy nacisnieto klawisz Esc, 0-Nacisnieto klawisz enter i wykonano wykonano ruch
	int ruch(int x, int y, char pole_gry[16][16], int gracz);
public:
	Player();
	// zwraca 1 gdy nacisnieto klawisz Esc 0 w innym przypadku
	virtual int wykonaj_ruch(char pole_gry[16][16], int pionek);
};


// klasa odpowiedzialana za wykonywanie ruchow komputera dziedziczy po klasie Players
class Cpu
	:public Players{
	int losuj(int i);
	int ruch(char plansza[16][16], int x, int y);
public:
	Cpu();
	virtual  int wykonaj_ruch(char pole_gry[16][16], int pionek);
};