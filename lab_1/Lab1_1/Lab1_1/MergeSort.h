#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;


void mergeSort_operator(vector<int>& income, size_t begin, size_t end); //size_t базовый беззнаковый целочисленный тип
void mergeSort_at(vector<int>& income, size_t begin, size_t end); 
void mergeSort_iterator(vector<int>& income, size_t begin, size_t end); 
void bubbleSort(vector<int>& income, size_t begin, size_t end);

void fillRandom(vector<double> income, size_t size);
void mergeSort(double& income, size_t begin, size_t end);

#endif // !MERGESORT_H
