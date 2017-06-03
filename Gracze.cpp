#include "Gracze.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <time.h>
#define _INCLUDE_LIST_H

using namespace std;

// klasa bazowa 
Players::Players() :rozmaiar_planszy(16),lista(NULL) {
	pionki[0] = 'H';
	pionki[1] = 'G';
	pionki[2] = 'F';
	pionki[3] = 'D';
	lista = new Lista_ruchow();
}

int Players::wykonaj_ruch(char pole_gry[16][16], int pionek){
	naglowek(pionek);
	for (int i = 0; i < 32; i++)
	{
		cout << "__";
	}
	cout << endl;
	for (int i = 0; i <rozmaiar_planszy; i++)
	{
		//podswietlanie odpowiedniego pola na planszy po kliknieciu strzalek
		for (int j = 0; j <rozmaiar_planszy; j++){
		
				if (rysuj(i, j)){
					cout << "| ";
				}
				else
					cout << ": ";

				cout << pole_gry[i][j] << " ";

			if (j == rozmaiar_planszy - 1)
			{
				if ((i == 5 && j == 15) || i == 10)
					cout << "| ";
				else
					cout << ":";
			}
		}
		//rysownie lini poziomej miedzy kratkami
		cout << endl;
		for (int j = 0; j < 32; j++)
		{

			cout << "--";
		}
		cout << endl;
	}
	return 0;
}

void Players::naglowek(int gracz){
	system("cls");

	cout << "Esc - Wyjscie" <<endl;
	cout << endl << "Gracz "<<gracz<<"-"<<getPionki(gracz)<< endl;
}

bool Players::rysuj(int x, int y){
	if (((x == 0 && y == 5) || (x == 1 && y == 4)) || ((x == 2 && y == 3) || (x == 3 && y == 2)) || (x == 4 && y == 1) || (x == 5 && y == 0)){
		return  true;
	}
	else if (((x == 0 && y == 11) || (x == 1 && y == 12)) || (x == 2 && y == 13) || (x == 3 && y == 14) || (x == 4 && y == 15)){
		return true;
	}
	else if (((x == 15 && y == 11) || (x == 14 && y == 12)) || (x == 13 && y == 13) || (x == 12 && y == 14) || (x == 11 && y == 15)){
		return true;
	}
	else if (((x == 15 && y == 5) || (x == 14 && y == 4)) || (x == 13 && y == 3) || (x == 12 && y == 2) || (x == 11 && y == 1) || (x == 10 && y == 0)){
		return true;
	}
	else
		return false;
}

char Players::getPionki(int i){
	return pionki[i-1];
}



void Players::lista_ruchow_stworz(int x, int y, char plansza[16][16]){

	Lista<int> *tail;

	if (y + 1 < rozmaiar_planszy){
		if (plansza[y + 1][x] == ' '){
			tail = new Lista<int>;
			tail->setX(x);
			tail->setY(y + 1);
			lista->dodaj(tail);
		}
		else if(y+2<16){
			if (plansza[y + 2][x] == ' '){
				tail = new Lista<int>;
				tail->setX(x);
				tail->setY(y + 2);
				lista->dodaj(tail);
			}
		}
	}


	if (y - 1 >= 0){
		if (plansza[y - 1][x] == ' '){
			tail = new Lista<int>;
			tail->setX(x);
			tail->setY(y - 1);
			lista->dodaj(tail);
		}
		else if(y-2>=0){
			if (plansza[y - 2][x] == ' '){
				tail = new Lista<int>;
				tail->setX(x);
				tail->setY(y - 2);
				lista->dodaj(tail);
			}
		}
	}

	if (x + 1 < rozmaiar_planszy){
		if (plansza[y][x + 1] == ' '){
			tail = new Lista<int>;
		    tail->setX(x + 1);
			tail->setY(y);
			lista->dodaj(tail);
		}
		else if(x+2<rozmaiar_planszy){
			if (plansza[y][x + 2] == ' '){
				tail = new Lista<int>;
				tail->setX(x + 2);
				tail->setY(y);
				lista->dodaj(tail);
			}
		}
	}

	if (x - 1 >= 0){
		if (plansza[y][x - 1] == ' '){
			tail = new Lista<int>;
			tail->setX(x - 1);
			tail->setY(y);
			lista->dodaj(tail);
		}
		else if(x-2>=0){
			if (plansza[y][x - 2] == ' '){
				tail = new Lista<int>;
				tail->setX(x - 2);
				tail->setY(y);
				lista->dodaj(tail);
			}
		}
	}

	if (y - 1 >= 0 && x + 1 < rozmaiar_planszy){
		if (plansza[y - 1][x + 1] == ' '){
			tail = new Lista<int>;
			tail->setX(x + 1);
			tail->setY(y - 1);
			lista->dodaj(tail);
		}
		else if(y-2>=0 && x+2<rozmaiar_planszy){
			if (plansza[y - 2][x + 2] == ' '){
				tail = new Lista<int>;
				tail->setX(x + 2);
				tail->setY(y - 2);
				lista->dodaj(tail);
			}
		}
	}

	if (y - 1 >= 0 && x - 1 >= 0){
		if (plansza[y - 1][x - 1] == ' '){
			tail = new Lista<int>;
			tail->setX(x - 1);
			tail->setY(y - 1);
			lista->dodaj(tail);
		}
		else if(y-2>=0 && x-2>=0){
			if (plansza[y - 2][x - 2] == ' '){
				tail = new Lista<int>;
				tail->setX(x - 2);
				tail->setY(y - 2);
				lista->dodaj(tail);
			}
		}
	}

	if (y+1<rozmaiar_planszy && x+1 <rozmaiar_planszy){
		if (plansza[y + 1][x + 1] == ' '){
			tail = new Lista<int>;
			tail->setX(x + 1);
			tail->setY(y + 1);
			lista->dodaj(tail);
		}
		else if(y+2<rozmaiar_planszy && x+2 <rozmaiar_planszy){
			if (plansza[y + 2][x + 2] == ' '){
				tail = new Lista<int>;
				tail->setX(x + 2);
				tail->setY(y + 2);
				lista->dodaj(tail);
			}
		}
	}

	if (y+1<rozmaiar_planszy && x-1>=0)
	if (plansza[y + 1][x - 1] == ' '){
		tail = new Lista<int>;
		tail->setX(x - 1);
		tail->setY(y + 1);
		lista->dodaj(tail);
	}
	else if(y+2<rozmaiar_planszy && x-2>=0){
		if (plansza[y + 2][x - 2] == ' '){
			tail = new Lista<int>;
			tail->setX(x - 2);
			tail->setY(y + 2);
			lista->dodaj(tail);
		}
	}

}

void Players::lista_ruchow_po_skoku_stworz(int x, int y,int x2,int y2, char plansza[16][16]){

	Lista<int> *tail = NULL;
	if (y + 2 < rozmaiar_planszy){
		if (plansza[y + 1][x] != ' ' && plansza[y + 2][x] == ' '){
			if (y + 2 != y2 && x != x2){
				tail = new Lista<int>;
				tail->setX(x);
				tail->setY(y + 2);
				lista->dodaj(tail);
			}
		}
	}

	if (y - 2 >= 0){
		if (plansza[y - 1][x] != ' ' && plansza[y - 2][x] == ' '){
			if (y - 2 != y2 && x != x2){
				tail = new Lista<int>;
				tail->setX(x);
				tail->setY(y - 2);
				lista->dodaj(tail);
			}
		}
	}

	if (x + 2 < rozmaiar_planszy){
		if (plansza[y][x + 1] != ' ' && plansza[y][x + 2] == ' '){
			if (y != y2 && x + 2 != x2){
				tail = new Lista<int>;
				tail->setX(x + 2);
				tail->setY(y);
				lista->dodaj(tail);
			}
		}
	}

	if (x - 2 >= 0){
		if (plansza[y][x - 1] != ' ' && plansza[y][x - 2] == ' '){
			if (y != y2 && x - 2 != x2){
				tail = new Lista<int>;
				tail->setX(x - 2);
				tail->setY(y);
				lista->dodaj(tail);
			}
		}
	}


	if (x + 2 < rozmaiar_planszy && y-2>=0){
		if (plansza[y - 1][x + 1] != ' ' && plansza[y - 2][x + 2] == ' '){
			if (y - 2 != y2 && x + 2 != x2){
				tail = new Lista<int>;
				tail->setX(x + 2);
				tail->setY(y - 2);
				lista->dodaj(tail);
			}
		}
	}


	if (x - 2 >= 0 && x-2>=0){
		if (plansza[y - 1][x - 1] != ' ' && plansza[y - 2][x - 2] == ' '){
			if (y - 2 != y2 && x - 2 != x2){
				tail = new Lista<int>;
				tail->setX(x - 2);
				tail->setY(y - 2);
				lista->dodaj(tail);
			}
		}
	}

	if (y + 2 < rozmaiar_planszy && x + 2 < rozmaiar_planszy){
		if (plansza[y + 1][x + 1] != ' ' && plansza[y + 2][x + 2] == ' '){
			if (y + 2 != y2 && x + 2 != x2){
				tail = new Lista<int>;
				tail->setX(x + 2);
				tail->setY(y + 2);
				lista->dodaj(tail);
			}
		}
	}

	if (y + 2 < rozmaiar_planszy && x - 2 <= 0){
		if (plansza[y + 1][x - 1] != ' ' && plansza[y + 2][x - 2] == ' '){
			if (y + 2 != y2 && x - 2 != x2){
				tail = new Lista<int>;
				tail->setX(x - 2);
				tail->setY(y + 2);
				lista->dodaj(tail);
			}
		}
	}

}

bool Players::sprawdz_skok(int x, int y, int x2, int y2, char plansza[16][16]){
	if (plansza[y + 1][x] != ' ' && plansza[y + 2][x] == ' ' && (y + 2 != y2 && x != x2)){
		return true;
	}

	if (plansza[y - 1][x] != ' ' && plansza[y - 2][x] == ' ' && (y - 2 != y2 && x != x2)){
		return true;
	}

		if (plansza[y][x + 1] != ' ' && plansza[y][x+2] == ' ' && (y != y2 && x + 2 != x2)){
		return true;
	}

	if (plansza[y][x - 1] != ' ' && plansza[y][x-2] == ' ' && (y != y2 && x -2  != x2)){
		return true;
	}

	if (plansza[y - 1][x + 1] != ' ' && plansza[y-2][x+2] == ' ' && (y - 2 != y2 && x + 2 != x2)){
		return true;
	}

	if (plansza[y - 1][x - 1] != ' ' && plansza[y-2][x-2] == ' ' && (y - 2 != y2 && x - 2 != x2)){
		return true;
	}

	if (plansza[y + 1][x + 1] != ' ' && plansza[y + 2][x+2] == ' ' && (y + 2 != y2 && x + 2 != x2)){
		return true;
	}

	if (plansza[y + 1][x - 1] != ' ' && plansza[y + 2][x-2] == ' ' && (y + 2 != y2 && x - 2 != x2)){
		return true;
	}
	if (plansza[y + 1][x + 1] != ' ' && plansza[y + 2][x+2] == ' ' && (y + 2 != y2 && x + 2 != x2))
	return true;

	return false;
}




// klasa odpowiadajaca za wykonywanie ruchow czlowieka
Player::Player() :Players(), enter(13), up(80), down(72), left(75), right(77), x(0), y(0){


}

int Player::ruch(int x, int y, char pole_gry[16][16], int gracz){

	int x3 = x, y3 = y;
	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);
	char pozycja;
	int x2 = x, y2 = y, z=0;
	lista_ruchow_stworz(x, y, pole_gry);
	for (;;)
	{
		
		naglowek(gracz);

		for (int i = 0; i < 32; i++)
		{
			cout << "__";
		}
		cout << endl;
		for (int i = 0; i < rozmaiar_planszy; i++)
		{

			for (int j = 0; j < rozmaiar_planszy; j++)
			{
				if (y == i &&x == j)
				{
					SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
					if (rysuj(i, j))
						cout << "| ";
					else
						cout << ": ";

					cout << pole_gry[i][j] << " ";
				}
				else if (j - 1 == x && y == i)
				{
					if (rysuj(i, j))
						cout << "| ";
					else
						cout << ": ";

					SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					cout << pole_gry[i][j] << " ";
				}

				else if (y2 == i &&x2 == j)
				{
					SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_BLUE);
					if (rysuj(i, j))
						cout << "| ";
					else
						cout << ": ";

					cout << pole_gry[i][j] << " ";
				}
				else if (j - 1 == x2 && y2 == i)
				{
					if (j - 2 == x&&y == i)
						SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_BLUE);
					if (rysuj(i, j))
						cout << "| ";
					else
						cout << ": ";
					SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					cout << pole_gry[i][j] << " ";
				}
				else
				{
					if (rysuj(i, j))
						cout << "| ";
					else
						cout << ": ";

					cout << pole_gry[i][j] << " ";
				}
				if (j == rozmaiar_planszy - 1)
				{
					if (i == 5 || i == 10)
						cout << "| ";
					else
						cout << ":";
					SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				}
			}

			cout << endl;
			for (int j = 0; j < 32; j++)
			{
				cout << "--";
			}
			cout << endl;
		}


		pozycja = _getch();

		if (pozycja == up){
			y2++;
			if (y2 >= rozmaiar_planszy)
				y2 = 0;
		}
		else if (pozycja == down){
			y2--;
			if (y2 <0)
				y2 = 15;
		}
		else if (pozycja == right){
			x2++;
			if (x2 >= rozmaiar_planszy)
				x2 = 0;
		}

		else if (pozycja == left){
			x2--;
			if (x2 < 0)
				x2 = 15;
		}
		// nacisniecie Esc
		else if (pozycja == 27){
			if (z)
				return 0;
			else{
				delete lista;
				return 1;
			}
		}
		else if (pozycja == enter)
		{
				if (lista->sprawdz_ruch(x2, y2))
				{
					pole_gry[y2][x2] = pole_gry[y][x];
					pole_gry[y][x] = ' ';
					x3 = x2;
					y3 = y2;
					if (sprawdz_skok(x3, y3, x, y, pole_gry))
					{
						z = 1;
						delete lista;
						lista = new Lista_ruchow();
						lista_ruchow_po_skoku_stworz(x2,y2,x,y, pole_gry);
						x = x2;
						y = y2;
						continue;
					}
					
					delete lista;
						return 0;
				}
				
		}
	}
}

int Player::wykonaj_ruch(char pole_gry[16][16], int pionek){

	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);

	for (;;)
	{
		system("cls");
		naglowek(pionek);
		for (int i = 0; i < 32; i++)
		{
			cout << "__";
		}
		cout << endl;
		for (int i = 0; i <rozmaiar_planszy; i++)
		{
			//podswietlanie odpowiedniego pola na planszy po kliknieciu strzalek
			for (int j = 0; j <rozmaiar_planszy; j++)
			{
				if (y == i &&x == j)
				{

					SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
					if (rysuj(i, j)){
						cout << "| ";
					}
					else
						cout << ": ";

					cout << pole_gry[i][j] << " ";
				}

				else if (rysuj(i, j)){
					if (y == i &&x == j){
						SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "| ";
					}
					else{

						cout << "| ";
					}
					SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					cout << pole_gry[i][j] << " ";
				}

				else if (j - 1 == x)
				{

					if (rysuj(i, j)){
						SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "| ";
					}
					else
						cout << ": ";

					SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					cout << pole_gry[i][j] << " ";
				}
				else
				{
					cout << ": ";
					cout << pole_gry[i][j] << " ";
				}
				if (j == rozmaiar_planszy - 1)
				{
					if ((i == 5 && j == 15) || i == 10)
						cout << "| ";
					else
						cout << ":";

					SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				}
			}
			//rysownie lini poziomej miedzy kratkami
			cout << endl;
			for (int j = 0; j < 32; j++)
			{

				cout << "--";
			}
			cout << endl;
		}


		pozycja = _getch();
		//sterowanie polozeniem kursora strzalki gora, dol,prawo,lewo
		if (pozycja == up){
			y++;
			if (y >= rozmaiar_planszy)
				y = 0;
		}
		else if (pozycja == down){
			y--;
			if (y <0)
				y = rozmaiar_planszy - 1;
		}
		else if (pozycja == right){
			x++;
			if (x >= rozmaiar_planszy)
				x = 0;
		}

		else if (pozycja == left){
			x--;
			if (x < 0)
				x = rozmaiar_planszy - 1;
		}
		else if (pozycja == enter)   // po nacisnieciu klaiwsza enter podswietlana zostaje wybrane pole i kursor zmienia kolor
		{
			if (pole_gry[y][x] != ' ' && pole_gry[y][x] == getPionki(pionek)){
				if (ruch(x, y, pole_gry, pionek))
					continue;
			}

			else
				continue;
			return 0;
		}
		else if (pozycja == 78 || pozycja == 110)		//nacisniecie klawisza 'n' na klawiaturze
		{
			//nowa_gra();
		}
		else if (pozycja == 27)		// nacisniecie klawisza Esc

			return 1;
	}
}



// klasa odpowiadajaca za ruchy komputera
Cpu::Cpu() :Players(){

}


int Cpu::losuj(int i){
	
	if (i == 0)
		i = 14;
	return rand() % i + 1;
}
int Cpu::ruch(char plansza[16][16],int x, int y){
	int i = 0;
	Lista<int> *wspolrzedne = NULL;
	
	lista_ruchow_stworz(x, y, plansza);
	if (lista->getDlugosc() == 0)
		return 1;

	for (;;){
		
		if ((wspolrzedne = lista->sprawdz_ruch_cpu(losuj(lista->getDlugosc() - 1))) == NULL && i == 1){
			delete lista;
			return 0;
		}

		plansza[wspolrzedne->getY()][wspolrzedne->getX()] = plansza[y][x];
		plansza[y][x] = ' ';

		if (sprawdz_skok(wspolrzedne->getX(), wspolrzedne->getY(),x,y, plansza)){
			i = 1;
			int x2 = wspolrzedne->getX();
			int y2 = wspolrzedne->getY();
			x = x2;
			y = y2;
			delete lista;
			lista = new Lista_ruchow();
			lista_ruchow_po_skoku_stworz(x2, y2, x, y, plansza);
		}
		else
			return 0;
	}

}
int Cpu::wykonaj_ruch(char pole_gry[16][16], int pionek){

	int x = losuj(14), y=losuj(14);

	while (pole_gry[y][x] != getPionki(pionek)){
		x = losuj(14);
		y = losuj(14);
	}
	while (ruch(pole_gry, x, y)){
		while (pole_gry[y][x] != getPionki(pionek)){
			x = losuj(14);
			y = losuj(14);
		}
	}
	return 0;
}