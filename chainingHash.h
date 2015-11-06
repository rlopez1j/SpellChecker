#include "linkedList.h"
#include <iostream>
#include <string>

class chainingTable
{
private:
	//hash table conists of a table of lists
	linkedList * table;
	//size of table
	int capacity;

	//number of items in hash table
	int numItems;

	int createKey(string c)
	{
		unsigned int key = 0;

		for (int i = 0; i < c.size(); i++)
			key = 37* key + c.at(i);

		return key%capacity;
	}

	void insert(int key, string word) 
	{
		table[key].enqueue(word);
		numItems++;
	}

public:
	chainingTable()
	{
		capacity = 101;
		table = new linkedList[capacity];
		numItems = 0;
	}

	chainingTable(int cap)
	{
		capacity = cap;
		table = new linkedList[capacity];
		numItems = 0;
	}
	
	void insert(string s) { insert(createKey(s),s); }

	bool contains(string s)
	{
		int key = createKey(s);
		return table[key].contains(s);
	}

	//use this to measure how good your
	//hash function is.
	double averageSearchCost()
	{
		double sumSquares=0;
		
		for(int i=0; i<capacity; i++)
			sumSquares += (table[i].size()*table[i].size());
			
		return sumSquares/numItems;
	}

};
