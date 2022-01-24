#include "funkcje.h"

using namespace std;

bool read_tree(ifstream &file, vector<Node> &tree )
{
	Node temp;
	int index;
	string warunek;
	while (!file.eof())
	{
		file >> index;
		file >> warunek;
		//parse_string(warunek, temp);
		if (!parse_string(warunek, temp))
		{
			return false;
		}
		else
		{
			file >> temp.NIE >> temp.TAK;
			file.ignore(255, '\n');
			if (tree.size() <= index)
				tree.resize(index + 1);
			tree[index] = temp;

		}
	}
	return true;
}
string znajdz_etykiete(const vector<float> &att_values, const vector<Node> &tree, const vector<string> &attributes)
{
	string wynik = "";
	string next;
	Node current_node = tree[0];
	while (wynik == "")
	{
		for(int i = 0; i<attributes.size(); i++)
		{
			if(attributes[i] == current_node.att)
			{
				if (current_node.znak == '<')
				{
					if (att_values[i] < current_node.wartosc)
						next = current_node.TAK;
					else
						next = current_node.NIE;
				}
				else
				{
					if (att_values[i] > current_node.wartosc)
						next = current_node.TAK;
					else
						next = current_node.NIE;
				}
				break;
			}
			
		}
		if (isdigit(next[0]))
		{
			current_node = tree[atoi(next.c_str())];
		}
		else
			wynik = next;
			
	}
	return wynik;
}

void read_data(ifstream& file2, vector<vector<float>> &dane,  vector <string> &atrybuty)
{
	
	string first_line;
	string atrybut;
	getline(file2, first_line, '\n');
	size_t position = first_line.find('%');
	if (position != string::npos)
		first_line = first_line.substr(0, position);
	istringstream iss(first_line);
	while (getline(iss, atrybut, ' ' ))
	{
		atrybuty.push_back(atrybut);
	}
	
	

	while (!file2.eof())
	{
		string wartosc;
		vector<float> att_values;
		for (int i = 0; i < atrybuty.size(); i++)
		{
			file2 >> wartosc;
			att_values.push_back(atof(wartosc.c_str()));
		}
		
		file2.ignore(255, '\n');
		dane.push_back(att_values);
		
	}
	
}

bool parse_string (string warunek, Node &node)
{
	string atrybut = "";
	bool znak_znaleziony = false;
	string wartosc = "";
	for (unsigned int i = 0; i < warunek.length(); i++)
	{
		if (warunek[i] == '>' || warunek[i] == '<' )
		{
			node.znak = warunek[i];
			znak_znaleziony = true;
			
		}
		else if(znak_znaleziony)
			wartosc += warunek[i];
		
		else
			atrybut += warunek[i];
				
	}
	if (!znak_znaleziony)
	{
		cout << "Niepoprawna struktura pliku drzewa";
		return false;
	}
	float liczba = atof(wartosc.c_str());
	node.att = atrybut;
	node.wartosc = liczba;
	return true;
}

void save_to_file(ofstream &plikwyj, const unordered_map<string, vector<vector<float>>> &wyniki)
{

	for (auto& it : wyniki) {
		plikwyj << it.first << '\n';

		for (int i = 0; i < it.second.size(); i++)
		{

			for (int j = 0; j < it.second.at(0).size(); j++)
			{
				plikwyj << it.second.at(i).at(j) << " ";
			}
			plikwyj << endl;
		}

	}
	plikwyj.close();
}