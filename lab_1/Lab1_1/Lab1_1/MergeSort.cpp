#include "MergeSort.h"


void mergeSort_operator(vector<int>& income, size_t begin, size_t end) {

	if (end - begin < 2)
		return;
	if (end - begin == 2) {
		if (income[begin] > income[begin + 1])
			swap(income[begin], income[begin + 1]);
		
		return;
	}

	mergeSort_operator(income, begin, begin + (end - begin) / 2);
	mergeSort_operator(income, begin + (end - begin) / 2, end);

	vector<int> tmp;
	size_t tmp_begin_first = begin;					  //начало первой половинки
	size_t tmp_end_first = begin + (end - begin) / 2; //конец первой половинки
	size_t tmp_begin_second = tmp_end_first;		  //начало второй половинки, конец второй - end

	while (tmp.size() < end - begin) {
		//не осталось ни одного элемента в какой-либо из половинок
		//если tmp_begin_first вышла за пределы массива то будем перекидывать элементы из tmp
		//после || если tmp_begin second < end
		if ( tmp_begin_first >= tmp_end_first || (tmp_begin_second < end && income[tmp_begin_second] <= income[tmp_begin_first])) {
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


void mergeSort_at(vector<int>& income, size_t begin, size_t end) {

	if (end - begin < 2)
		return;
	if (end - begin == 2) {
		if (income[begin] > income[begin + 1])
			swap(income.at(begin), income.at(begin + 1));

		return;
	}

	mergeSort_at(income, begin, begin + (end - begin) / 2);
	mergeSort_at(income, begin + (end - begin) / 2, end);

	vector<int> tmp;
	size_t tmp_begin_first = begin;					  //начало первой половинки
	size_t tmp_end_first = begin + (end - begin) / 2; //конец первой половинки
	size_t tmp_begin_second = tmp_end_first;		  //начало второй половинки, конец второй - end

	while (tmp.size() < end - begin) {
		//не осталось ни одного элемента в какой-либо из половинок
		//если tmp_begin_first вышла за пределы массива то будем перекидывать элементы из tmp
		//после || если tmp_begin second < end
		if (tmp_begin_first >= tmp_end_first || (tmp_begin_second < end && income.at(tmp_begin_second) <= income.at(tmp_begin_first))) {
			tmp.push_back(income.at(tmp_begin_second));
			++tmp_begin_second;
		} else {
			tmp.push_back(income.at(tmp_begin_first));
			++tmp_begin_first;
		}

	}

	for (size_t i = begin; i < end; ++i) {
		income.at(i) = tmp.at(i - begin);
	}

}


void bubbleSort(vector<int>& income, size_t begin, size_t end) {

	for (auto i = income.begin(); i != income.end(); i++) {
		for (auto j = income.end() - 1; j > i; j--) {
			if (*(j - 1) > * j) {			

				int tmp = *(j - 1);
				*(j - 1) = *j;
				*j = tmp;

			}
		}
	}

}


void fillRandom(vector<double> &income, size_t size) {
	srand(time(NULL));
	for (size_t i = 0; i < size; i++)
		income[i] = (rand() % 11 - 10) / RAND_MAX;

}

//void mergeSort_iterator(vector<int>& income, size_t begin, size_t end) {
//
//	if (end - begin < 2)
//		return;
//	if (end - begin == 2) {
//		if (begin > begin + 1) {
//			
//			vector<int>::iterator _begin = income.begin();
//			vector<int>::iterator _end = income.end();
//			vector<int>::iterator _tmp;
//			_tmp = _begin;
//			_begin = _end;
//			_end = _tmp;
//		}
//
//		return;
//	}
//
//	mergeSort_at(income, begin, begin + (end - begin) / 2);
//	mergeSort_at(income, begin + (end - begin) / 2, end);
//
//	vector<int> tmp_left(, tmp_right;
//	
//	vector<int>::iterator tmp_begin_first = tmp.begin();			            //начало первой половинки
//	vector<int>::iterator tmp_end_first = tmp_begin_first + (end - begin) / 2;  //конец первой половинки
//	vector<int>::iterator tmp_begin_second = tmp_end_first;		                //начало второй половинки, конец второй - end
//	while (tmp.size() < end - begin) {
//		//не осталось ни одного элемента в какой-либо из половинок
//		//если tmp_begin_first вышла за пределы массива то будем перекидывать элементы из tmp
//		//после || если tmp_begin second < end
//		if (*tmp_begin_first >= *tmp_end_first || (tmp_begin_second < tmp.end())) {
//			tmp.push_back(*tmp_begin_second);
//			++tmp_begin_second;
//		} else {
//			tmp.push_back(*tmp_begin_first);
//			++tmp_begin_first;
//		}
//
//	}
//
//	income = tmp;
//
//}