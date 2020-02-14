#include "Source.h"
using namespace std;
void fillRandom(double* income, int size) {

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
	size_t tmp_begin_first = begin;					  //íà÷àëî ïåðâîé ïîëîâèíêè
	size_t tmp_end_first = begin + (end - begin) / 2; //êîíåö ïåðâîé ïîëîâèíêè
	size_t tmp_begin_second = tmp_end_first;		  //íà÷àëî âòîðîé ïîëîâèíêè, êîíåö âòîðîé - end

	while (tmp.size() < end - begin) {
		//íå îñòàëîñü íè îäíîãî ýëåìåíòà â êàêîé-ëèáî èç ïîëîâèíîê
		//åñëè tmp_begin_first âûøëà çà ïðåäåëû ìàññèâà òî áóäåì ïåðåêèäûâàòü ýëåìåíòû èç tmp
		//ïîñëå || åñëè tmp_begin second < end
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
