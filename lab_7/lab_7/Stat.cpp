#include "Stat.h"

using namespace std;


Stat::Stat() {
	min_val			= 0;
	max_val			= 0;
	first_value		= 0;
	last_value		= 0;
	amount_positive = 0;
	amount_negative = 0;
	sum_even		= 0;
	sum_odd			= 0;
	calls			= 0;
	sum				= 0;
}


void Stat::operator()(int value) {

	if (first_value == 0) {
		min_val = value;
		max_val = value;
		first_value = value;
		
	}
	last_value = value;
	if (value < min_val) min_val = value;

	if (value > max_val) max_val = value;

	if (value < 0) ++amount_negative;
	if (value > 0) ++amount_positive;

	if (value % 2 == 0) sum_even += value;
	else sum_odd += value;

	sum += value;
	++calls;

}


void Stat::getStatics() {

	cout << endl;
	cout << "The first element in the list: " << first_value << ";" <<endl;
	cout << "The last element in the list: " << last_value << ";" << endl;
	cout << "Average value: " << sum / calls << ";" << endl;
	cout << "Amount of positive: " << amount_positive << ";" << endl;
	cout << "Amount of negative: " << amount_negative << ";" << endl;
	cout << "Sum of odd values: " << sum_odd << ";" << endl;
	cout << "Sum of even values: " << sum_even << ";" << endl;
	cout << "first value ";
	if (first_value == last_value) cout << "equals last";
	else cout << "does not equals last";

	cout << endl;

}

