#include "Solution.h"
#include <algorithm>
#include <iostream>
#include <list>

Solution::Solution() {

	for (int i = 0; i < 15; i++)
		solutionList.push_back(rand() % 20 + 1);
	lenght = 15;

}

Solution::Solution(int value) {	
	if (value >= 20) {
		std::cout << std::endl << "You can create only in range of 1:15" << std::endl;
		value = 15;
	}
	for (int i = 0; i < value; i++)
		solutionList.push_back(rand() % 20 + 1);
	lenght = value;

}

void Solution::regularPrint() {
	std::cout << std::endl;
	for (auto it = solutionList.begin(); it != solutionList.end(); ++it)
		std::cout << *it << " ";
}

int Solution::length() {
	return this->lenght;
}

bool Solution::append(int value) {
	if (lenght == 20) {
		std::cout << std::endl << "You can not append new value. The list is full.";
		std::cout << std::endl << "Current amaunt of values: " << lenght;
		return false;
	}

	if (value >= 1 && value <= 20) {
		solutionList.push_back(value);
		++lenght;
		return true;
	} else {
		std::cout << std::endl << "the value is not in range 1:20." << std::endl;
		return false;
	}
}

void Solution::print() {
	if (lenght == 1) {
		std::cout << std::endl << solutionList.front();
		return;
	} else if (lenght == 0) {
		std::cout << std::endl << "Nothing to print";
		return;
	}
	int first = 0, last = lenght - 2;
	std::cout << std::endl;
	std::cout << *solutionList.begin() << " " << solutionList.back() << " ";
	while ((first != last) && (first < last)) {
		auto it = solutionList.begin();
		for (int i = 0; i <= first; i++)
			++it;
		std::cout << *it << " ";
		if (!(first + 1 <= last - 1)) break;
		it = solutionList.begin();
		for (int i = 0; i < last; i++)
			++it;
		std::cout << *it << " ";
		++first;
		--last;
	}
}