#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H
#include <list>


class Solution {
private:
	std::list<int> solutionList;
	int		lenght = 0;

public:
	//default constructor
	Solution();
	//constructor with amount of arguments as income value
	Solution(int);
	void	regularPrint();
	int		length();
	bool	append(int);
	void	print();
};

#endif // SOLUTION_H