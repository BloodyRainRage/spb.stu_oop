#pragma once
#ifndef STAT_H
#define STAT_H
#include <vector>
#include <iostream>


class Stat {

private:
	

	int	min_val;
	int	max_val;
	int	first_value;
	int	last_value;
	int	sum;
	int amount_positive;
	int amount_negative;
	int sum_even;
	int sum_odd;
	int calls;
public:
	Stat();
	void operator() (int);
	void getStatics();

};


#endif // !STAT_H