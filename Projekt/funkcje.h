/**
* \file
*/

#ifndef FUNKCJE_H
#define FUNKCJE_H
#include "struktury.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

/** Funkcja wczytująca z pliku struktura.txt strukturę drzewa do podanego wektora tree
* @param file Plik drzewa
* @param tree Wektor przechowywujący strukturę drzewa
* @return Funkcja zwraca false w przypadku nieprawidłowego warunku, a true po skutecznym wczytaniu warunku
*/
bool read_tree(ifstream &file, vector<Node> &tree);

/** Funkcja wyłuskuje z parametru warunek, nazwę atrybutu, znak i wartość oraz zapisuje je do parametru node
* @param warunek Przechowuje warunek
* @param node Struktura węzła drzewa
* @return Funkcja zwraca false w przypadku nieprawidłowego warunku, a true po skutecznym wczytaniu struktury
*/
bool parse_string(string warunek, Node &node);
/** Funkcja wczytuje etykiety oraz wartości z pliku dane.txt, zapisuje je do wektorów, podane jako parametry funkcji
* @param file2 Plik z danymi
* @param dane Wektor z przykładami
* @param atrybuty Wektor z atrybutami
* @return Funkcja nie zwraca niczego
*/
void read_data(ifstream& file2, vector<vector<float>>& dane, vector <string>& atrybuty);
/** Funkcja znajduje etykietę i przypisuje jej wartości
* @param att_values Wektor z wartościami atrybutów
* @param tree Wektor węzłów drzewa
* @param attributes Wektor z atrybutami
* @return Funkcja zwraca etykietę dla zestawu danych
*/
string znajdz_etykiete(const vector<float>& att_values, const vector<Node>& tree, const vector<string>& attributes);
/** Funkcja zapisuje już przypisane wartości i etykiety do pliku "wyjscie.txt"
* @param plikwyj Plik wyjściowy
* @param wyniki Przydzielone już przykłady do etykiet
* @return Funkcja nie zwraca niczego
*/
void save_to_file(ofstream& plikwyj, const unordered_map<string, vector<vector<float>>>& wyniki);


#endif 
