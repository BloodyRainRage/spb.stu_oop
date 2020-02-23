#include "Header.h"
#include <iostream>

using namespace std;

void readFile(ifstream& f, vector<string>& table) {

	string str;

	while (getline(f, str))
		table.push_back(str);

}


DataStruct fillStruct(vector<string> table) {

	DataStruct ds;
	ds.key1 = rand() % 11 - 5;
	ds.key2 = rand() % 11 - 5;
	ds.str = table.at(rand() % table.size());

	return ds;
}

bool needToSwap(DataStruct a, DataStruct b) {

	if (a.key1 > b.key1)
		return true;
	if ((a.key2 > b.key2) && (a.key1 == b.key1))
		return true;
	if ((a.str.length() > b.str.length()) && (a.key2 == b.key2) && (a.key1 == b.key1))
		return true;
	return false;

	/*if (a.key1 < b.key1)
		return true;
	else if ((a.key2 < b.key2) && a.key1 == b.key1)
		return true;
	else if (a.str.length() < b.str.length())
		return true;
	else return false;*/

}

void sort(vector<DataStruct> &income) {

	for (int i = 0; i < income.size(); ++i)
	{
		for (int j = i + 1; j < income.size(); ++j)
		{
			if (needToSwap(income[i], income[j])) {
				DataStruct temp = income[i];
				income[i] = income[j];
				income[j] = temp;
			}
		}
	}
}


void print(vector<DataStruct> income) {
	cout << endl;
	for (int i = 0; i < income.size(); ++i) {
		printf("\tkey1=%2d \tkey2=%2d \tstr=%s \t\n", income[i].key1, income[i].key2, income[i].str.c_str());
	}

}