#include "List.h"
#define _INCLUDE_LIST_H


template<typename T>
Lista<T>::Lista():nast(NULL),x(-1),y(-1){

}

template<typename T>
T Lista<T>::getX(){
	return x;
}
template<typename T>
T Lista<T>::getY(){
	return y;
}
template<typename T>
void Lista<T>::setX(int x2){
	if (x2 >= 0 && x2 < 16)
		x = x2;
}

template<typename T>
void Lista<T>::setY(int y2){
	if (y2 >= 0 && y2 < 16)
		y = y2;
}

template<typename T>
Lista<T> * Lista<T>::sprawdz(T x2, T y2){
	if (x2 == x && y2 == y){
		return this;
	}
	else {
		if (nast != NULL){
			return nast->sprawdz(x2,y2);
		}
		else{
			return NULL;
		}
	}
}

template<typename T>
Lista<T>::~Lista(){
	delete nast;
}





Lista_ruchow::Lista_ruchow():head(NULL),tail(NULL),dlugosc(0),j(0){

}

int Lista_ruchow::getDlugosc(){
	return dlugosc;
}

void Lista_ruchow::dodaj(Lista<int> *l){
	if (head != NULL){
		tail->nast = l;
		tail = tail->nast;
		dlugosc++;
	}
	else{
		head = l;
		tail = head;
		dlugosc++;
	}

}

bool Lista_ruchow::sprawdz_ruch(int x, int y){
	Lista<int> *pom;
	if (head != NULL){
		pom = head->sprawdz(x, y);
		if (pom != NULL)
			return true;
		else
			return false;
	}
	else
		return false;
}

Lista<int> * Lista_ruchow::sprawdz_ruch_cpu(int i){
	Lista<int> *pom = head;
	while (pom != NULL && j <= i){
		if (i == j){
			j = 0;
			return pom;
		}
		pom = pom->nast;
		j++;
	}
	return NULL;
}

Lista_ruchow::~Lista_ruchow(){
	delete head;
}