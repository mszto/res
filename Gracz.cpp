#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include "Gracz.h"
using namespace std;



Player::Player():Players(), enter(13), up(80),down(72),left(75),right(77),x(0),y(0){


}


bool Player::sprawdz_ruch(int x, int y, int x2, int y2){
	return true;
}

void Player::ruch(int x, int y, char pole_gry[16][16]){

	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);
	char pozycja;
	int x2 = x, y2 = y;

	for (;;)
	{
		naglowek();

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
		else if (pozycja == 27)
			return;
		else if (pozycja == 78 || pozycja == 110)
		{
			//nowa_gra();
			return;
		}
		else if (pozycja == enter)
		{
			if (pole_gry[y2][x2] == ' ')
			{
				bool pom, ol;

				ol = sprawdz_ruch(x, y, x2, y2);
				if (ol)
				{
					pole_gry[y2][x2] = pole_gry[y][x];
					pole_gry[y][x] = ' ';
				}
				else
					break;
			}
		}
	}
}

void Player::wykonaj_ruch(char pole_gry[16][16], int pionek){

	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);

	for (;;)
	{
		system("cls");
		naglowek();
		for (int i = 0; i < 32; i++)
		{
			cout << "__";
		}
		cout << endl;
		for (int i = 0; i <rozmaiar_planszy ; i++)
		{
			//podswietlanie odpowiedniego pola na planszy po kliknieciu strzalek
			for (int j = 0; j <rozmaiar_planszy  ; j++)
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
				if (j == rozmaiar_planszy-1)
				{	
					if ((i == 5 && j == 15) || i==10)
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
				y = rozmaiar_planszy-1;
		}
		else if (pozycja == right){
			x++;
			if (x >= rozmaiar_planszy)
				x = 0;
		}

		else if (pozycja == left){
			x--;
			if (x < 0)
				x = rozmaiar_planszy-1;
		}
		else if (pozycja == enter)   // po nacisnieciu klaiwsza enter podswietlana zostaje wybrane pole i kursor zmienia kolor
		{
			if (pole_gry[y][x] != ' ' && pole_gry[y][x] == getPionki(pionek))
			ruch(x, y,pole_gry);
		}
		else if (pozycja == 78 || pozycja == 110)		//nacisniecie klawisza 'n' na klawiaturze
		{
			//nowa_gra();
		}
		else if (pozycja == 27)		// nacisniecie klawisza Esc
			
			return ;
	}
}



