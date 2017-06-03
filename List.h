#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;



template <typename T>
class Lista{
	T x;
	T y;
public:
	Lista *nast;

	Lista();
	void setX(int x);
	void setY(int y);
	T  getX();
	T getY();
	Lista * sprawdz(T x, T y);
	~Lista();
};


class Lista_ruchow{
	Lista<int> *head;
	Lista<int> *tail;
	int dlugosc;
	int j;
public:
	Lista_ruchow();
	void dodaj(Lista<int> *l);
	int getDlugosc();
	bool sprawdz_ruch(int x, int y);
	Lista<int> * sprawdz_ruch_cpu(int i);
	~Lista_ruchow();
};



