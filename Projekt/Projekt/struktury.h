/**
* \file
*/
#ifndef STRUKTURY_H
#define STRUKTURY_H


using namespace std;
#include <iostream>

/** Struktura opisująca poszczególne wierzchołki drzewa
*
* @param att Nazwa atrybutu
* @param znak operator
* @param wartosc wartość liczbowa atrybutu
* @param TAK wyjście z aktualnego wierzchołka kiedy warunek jest spełniony
* @param NIE wyjście z aktualnego wierzchołka kiedy warunek nie jest spełniony
*/

struct Node
{
	string att; 
	char znak; 
	float wartosc; 
	string TAK; 
	string NIE; 

};

#endif