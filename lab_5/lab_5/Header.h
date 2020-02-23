#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <vector>
#include <fstream>


struct DataStruct {
	int key1;
	int key2;
	std::string str;
};

//reading table from file
void readFile(std::ifstream&, std::vector<std::string>&);

//filling a new DataStruct
DataStruct fillStruct(std::vector<std::string>);

//sortin a vector of DataStruct
void sort(std::vector<DataStruct>&);
//Check if should two values be swapped
bool needToSwap(DataStruct, DataStruct);

//printing a vector of DataStruct
void print(std::vector<DataStruct>);

#endif // !HEADER_H

