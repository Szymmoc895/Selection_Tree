#include "funkcje.h"

using namespace std;

int main(int argc, char* argv[])
{
	vector<Node> tree;
	unordered_map<string, vector<vector<float>>> wyniki;
	vector<vector<float>> dane;
	vector<string> nazwy_atrybutow;
	if (argc == 7)
	{
		ofstream plikwyj;
		
		for (int i = 1; i < 7; i+=2)
		{
			string file_name = argv[i+1];
			string arg = argv[i];
			if (arg == "-i")
			{
				ifstream plikwej(file_name);
				if (plikwej.is_open()) {

					read_data(plikwej, dane, nazwy_atrybutow);
				}
				else
				{
					cout << "Nie udalo sie otworzyc pliku!"<<endl;
					return 4;
				}

			}
			else if (arg == "-t")
			{
				ifstream plikdrzewa(file_name);
				if (plikdrzewa.is_open())
				{
					//read_tree(plikdrzewa, tree);
					if (!read_tree(plikdrzewa, tree))
					{
						return 6;
					}

				}
				else
				{
					cout << "Nie udalo sie otworzyc pliku!" << endl;
					return 3;
				}
			}
			else if (arg == "-o")	
			{
				plikwyj.open(file_name);
				if (!plikwyj.is_open()) {

					cout << "Nie udalo sie otworzyc pliku!" << endl;
					return 2;
				}
			}
			else 
			{
				cout << "Nieprawidlowo podano parametr!\nProgram uruchamiany jest przy pomocy nastepujacych przelacznikow:\n";
				cout << "-i - plik_wejsciowy \n-t - plik_drzewa \n-o - plik_wyjsciowy" << endl;
				return 5;
			}
		}
		for (int i = 0; i < dane.size(); i++)
		{
			string etykieta = znajdz_etykiete(dane.at(i), tree, nazwy_atrybutow);
			wyniki[etykieta].push_back(dane.at(i));

		}
		save_to_file(plikwyj, wyniki);
	}
	else
	{
		cout << "Podano za malo argumentow.\nProgram uruchamiany jest przy pomocy nastepujacych przelacznikow:\n";
		cout << "-i - plik_wejsciowy \n-t - plik_drzewa \n-o - plik_wyjsciowy" << endl;
	}
}

