#include <iostream>
#include <fstream>
#include "chainingTable.h"
using namespace std;

void readIn(string filename, chainingTable &table)
{
	ifstream f;
	f.open("dictionary.txt");

	string word;
	while (!f.eof())
	{
		f >> word;
		table.insert(word);
	}
}
