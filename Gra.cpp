#include "Gra.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

#define _INCLUDE_LIST_H

 Gra::Gra() : rozmiar_planszy(16), gracz(NULL){
	for (int i = 0; i < rozmiar_planszy; i++){
		for (int j = 0; j < rozmiar_planszy; j++){

			if (i >= 0 && i < 5){
				if (j < 5 - i){
					pole_gry[i][j] = 'H'; 
				}
				else if (j>10 + i){
					pole_gry[i][j] = ' ';
				}
				else{
					pole_gry[i][j] = ' ';
				}
			}
			else if (i<16 && i>10){
				if (i-j>10)
					pole_gry[i][j] = ' ';
				else if (i+j>25)
					pole_gry[i][j] = 'G';
				else
					pole_gry[i][j] = ' ';
			}
			else{
				pole_gry[i][j] = ' ';
			}
			
		}			
	}
	losuj_kolejnosc(4);
}


void Gra::losuj_kolejnosc(int ile){
	
	for (int i = 0; i < ile; i++){
			gracze[i] = rand()%ile + 1;

				for (int j = 0; j < i; j++){
					while(gracze[i] == gracze[j]){
						gracze[i] = rand() % ile + 1;
					}
			}
	}
}


void Gra::start(int ile_cpu){
	losuj_kolejnosc(2);
	
	while (true){
		if (ile_cpu == 1){
			if (gracze[0] == 2){
				gracz = new Cpu();
			}
			else{
				gracz = new Player();
			}
			if (gracz->wykonaj_ruch(pole_gry, gracze[0]))
				return;
			if (sprawdz_wygrana(this, gracz) != 4){
				delete gracz;
				gracz = new Players();
				gracz->wykonaj_ruch(pole_gry, 2);
				cout << "Wygrywa Gracz " << gracze[0] << "!!" << endl;
				cout << "Nacisnij Enter";
				while (_getch() != 13){

				}
				return;
			}
			int pom = gracze[1];
			gracze[1] = gracze[0];
			gracze[0] = pom;
			delete gracz;
		}
		else{
			gracz = new Player();
			if (gracz->wykonaj_ruch(pole_gry, gracze[0]))
				return;
			if (sprawdz_wygrana(this, gracz) != 4){
				delete gracz;
				gracz = new Players();
				gracz->wykonaj_ruch(pole_gry, 2);
				cout << "Wygrywa Gracz " << gracze[0]<<"!!"<< endl;
				cout << "Nacisnij Enter";
				while (_getch() != 13){

				}
				return;
			}
			int pom = gracze[1];
			gracze[1] = gracze[0];
			gracze[0] = pom;
			delete gracz;
		}

	}
}



int sprawdz_wygrana(const Gra *g,Players *p){
	for (int k = 0; k < 4; k++){
		int l = 1;
		if (k == 1){
			for (int i = 0; i <5; i++){

				for (int j = 4-i; j >= 0; j--){
					if (g->pole_gry[i][j] != p->getPionki(k+1))
						l=0;
				}
			}
			if (l)
			return 0;
		}
		
		if (k == 0){
			for (int i = 11; i < 16; i++){

				for (int j = 15; j > 25-i; j--){
					if (g->pole_gry[i][j] != p->getPionki(k+1))
						l = 0;
				}
			}
			if (l)
			return 0;
		}

		if (k == 2){
			for (int i = 0; i <=4; i++){

				for (int j = 15; j >= 11+i; j--){
					if (g->pole_gry[i][j] != p->getPionki(k+1))
						l = 0;
				}
			}
			if (l)
			return 2;
		}

		if (k == 3){
			for (int i = 11; i <= 15; i++){

				for (int j = 0; j < i%10 - 1; j++){
					if (g->pole_gry[i][j] != p->getPionki(k+1))
						l = 0;
				}
			}
			if (l)
			return 3;
		}

		
	}

	return 4;
}
