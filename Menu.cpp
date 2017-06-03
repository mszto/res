
#include <iostream>
#include "Menu.h"
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;


void Menu::najlepszy_wynik()
{
	char znak;
	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);

	do
	{

		system("cls");
		cout << endl;
		cout << "---------------------" << endl;
		cout << "<<NAJLEPSI GRACZE>> " << endl;
		cout << "---------------------" << endl;
		cout << endl;
		cout << "   Gracz     Wynik" << endl << endl;
		for (int i = 0; i <= 4; i++)
		{
			cout << i + 1 << ". " << tab_wynikow[i].gracz << "   " << tab_wynikow[i].wynik << endl;
		}
		cout << endl;
		SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "wroc";
		SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

	} while (znak = _getch() != enter);
}

void Menu::wczytaj_wyniki()
{
	fstream plik;

	plik.open("wyniki.txt", ios::in);

	if (plik.good() == false)
	{

		plik.open("wyniki.txt", ios::out);
		for (int i = 0; i < 5; i++)
		{
			tab_wynikow[i].gracz = "GraczCpu";
			tab_wynikow[i].wynik = 10;
			plik << tab_wynikow[i].gracz << " " << tab_wynikow[i].wynik << endl;
		}
	}
	else
	{
		int i = 0;
		while (!plik.eof())
		{
			plik >> tab_wynikow[i].gracz >> tab_wynikow[i].wynik;
			if (plik.fail())
			{
				for (int i = 0; i < 5; i++)
				{
					tab_wynikow[i].gracz = "GraczCpu";
					tab_wynikow[i].wynik = 10;
				}
				break;
			}
			i++;
		}
	}
	plik.close();
}

void Menu::logo()
{
	cout << "----------------------" << endl;
	cout << "  <<MENU GLOWNE>>" << endl;
	cout << "----------------------" << endl;
}

int Menu::wyswietl()
{
	int pozycja = 1;
	unsigned char tmp;

	for (;;)
	{
		switch (pozycja)
		{
		case 1:

			HANDLE kolor;
			kolor = GetStdHandle(STD_OUTPUT_HANDLE);

			system("cls");
			logo();
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " 1. Nowa Gra" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << " 2. Najlepsze Wyniki" << endl;
			cout << " 3. Wyjscie" << endl;
			cout << endl;

			tmp = _getch();
			if (tmp == down)
			{
				pozycja = 3;
			}
			else if (tmp == up)
				pozycja++;
			else if (tmp == enter)
				return pozycja;
			break;
		case 2:
			kolor = GetStdHandle(STD_OUTPUT_HANDLE);

			system("cls");

			logo();

			cout << " 1. Nowa Gra" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " 2. Najlepsze Wyniki" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << " 3. Wyjscie" << endl;

			tmp = _getch();
			if (tmp == down)
				pozycja--;
			else if (tmp == up)
				pozycja++;
			else if (tmp == enter)
				return pozycja;
			break;
		case 3:

			kolor = GetStdHandle(STD_OUTPUT_HANDLE);

			system("cls");

			logo();

			cout << " 1. Nowa Gra" << endl;
			cout << " 2. Najlepsze Wyniki" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " 3. Wyjscie" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

			tmp = _getch();
			if (tmp == down)
				pozycja--;
			else if (tmp == up)
				pozycja = 1;
			else if (tmp == enter)
				return pozycja;
			break;
		default:
			break;
		}
	}
}

void Menu::wyjscie()
{
	char wyjscie;
	int pozycja = 1;

	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);

	while (pozycja != 3)
	{

		switch (pozycja)
		{
		case 1:
			system("cls");
			cout << "Czy na pewno chcesz wyjsc z gry ?";
			cout << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "Tak" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "Nie" << endl;
			wyjscie = _getch();
			if (wyjscie == enter)
				exit(0);
			else if (wyjscie == down || wyjscie == up)
				pozycja++;
			break;
		case 2:
			system("cls");
			cout << "Czy na pewno chcesz wyjsc z gry ?";
			cout << endl;
			cout << "Tak" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "Nie" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			wyjscie = _getch();
			if (wyjscie == enter)
				pozycja++;
			else if (wyjscie == down || wyjscie == up)
				pozycja--;
			break;
		}
	}

}

int Menu::gracz_cpu(){
	char wyjscie;
	int pozycja = 1;

	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);

	while (pozycja != 3)
	{

		switch (pozycja)
		{
		case 1:
			system("cls");
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "Gracz vs Gracz" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "Gracz vs CPU" << endl;
			wyjscie = _getch();
			if (wyjscie == enter)
				return 0;
			else if (wyjscie == down || wyjscie == up)
				pozycja++;
			break;
		case 2:
			system("cls");
			cout << "Gracz vs Gracz" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "Gracz vs Cpu" << endl;
			SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			wyjscie = _getch();
			if (wyjscie == enter)
				return 1;
			else if (wyjscie == down || wyjscie == up)
				pozycja--;
			break;
		}
	}
}