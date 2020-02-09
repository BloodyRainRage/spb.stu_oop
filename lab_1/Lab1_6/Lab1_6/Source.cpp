#include "Source.h"
using namespace std;
void fillRandom(double* income, int size) {

	srand(time(NULL));
	for (int i = 0; i < size; i++)
		income[i] = (rand()%21-10) * 0.1 ;		
	
}


void mergeSort(vector<double>& income, size_t begin, size_t end) {

	if (end - begin < 2)
		return;
	if (end - begin == 2) {
		if (income[begin] > income[begin + 1])
			swap(income[begin], income[begin + 1]);

		return;
	}

	mergeSort(income, begin, begin + (end - begin) / 2);
	mergeSort(income, begin + (end - begin) / 2, end);

	vector<double> tmp;
	size_t tmp_begin_first = begin;					  //начало первой половинки
	size_t tmp_end_first = begin + (end - begin) / 2; //конец первой половинки
	size_t tmp_begin_second = tmp_end_first;		  //начало второй половинки, конец второй - end

	while (tmp.size() < end - begin) {
		//не осталось ни одного элемента в какой-либо из половинок
		//если tmp_begin_first вышла за пределы массива то будем перекидывать элементы из tmp
		//после || если tmp_begin second < end
		if (tmp_begin_first >= tmp_end_first || (tmp_begin_second < end && income[tmp_begin_second] <= income[tmp_begin_first])) {
			tmp.push_back(income[tmp_begin_second]);
			++tmp_begin_second;
		} else {
			tmp.push_back(income[tmp_begin_first]);
			++tmp_begin_first;
		}

	}

	for (size_t i = begin; i < end; ++i) {
		income[i] = tmp[i - begin];
	}
}