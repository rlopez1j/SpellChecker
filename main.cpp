#include <iostream>
#include <string>
#include "SpellCheckFile.h"

int main()
{
	chainingTable hash(250'003);

	readIn("dictionary.txt", hash);

	string word1, word2, word3;
	word1 = "notaword";
	word2 = "hello";
	word3 = "sulfamethoxazole";

	if (hash.contains(word1))
		cout << "The word " << word1 << " is a real word" << endl;
	else
		cout << "The word " << word1 << " is not real word" << endl;

	if (hash.contains(word2))
		cout << "The word " << word2 << " is a real word" << endl;
	else
		cout << "The word " << word2 << " is not real word" << endl;
	
	if (hash.contains(word3))
		cout << "The word " << word3 << " is a real word" << endl;
	else
		cout << "The word " << word3 << " is not real word" << endl;

	cout << "My program's average search cost is: " << hash.averageSearchCost() << endl;

	spell_check_file("raven.txt", hash);

	return 0;
}
