#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include "readIn.h"
using namespace std;

string read_from_file(fstream &file)
{
	string s;
	file >> s;
	return s;
}

string cleaner(string word)
{
	for (int i = 0; i < word.size(); i++)
	{
		if ((int)word[i] >= 97 && word[i] <= 122) //if lowercase letter
		{}
		else if ((int)word[i] >= 65 && (int)word[i] < 91)
			word[i] = (int)word[i] + 32;	//changes to lowercase			
		else  //when not a letter at all
		{
			if (i == 0) //weird boundary condition for first char
			{
				word.erase(i, i + 1); 
				i--;
			}
			else
				word.erase(i, i);
		}
	}
	return word;
}

void output_misspelled_word(fstream &file, string misspelled)
{
	file << misspelled;
	file << endl;
}

void spellCheck(chainingTable table, fstream &outfile, string cleanWord)
{
	if (table.contains(cleanWord)){}
	else
		output_misspelled_word(outfile, cleanWord);
}

void spell_check_file(string filename, chainingTable table)
{
	string dirtyWord;
	string cleanWord;
	fstream file;
	fstream outfile;

	file.open(filename.c_str(), ios_base::in);
	outfile.open("output.txt");

	while (!file.eof())
	{
		dirtyWord = read_from_file(file);
		cleanWord = cleaner(dirtyWord);
		spellCheck(table, outfile, cleanWord);
	}

	file.close();
	outfile.close();
}
