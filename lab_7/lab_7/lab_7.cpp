// lab_7.cpp : by BadDragon

#include <iostream>
#include <vector>
#include <time.h>
#include "Stat.h"
#include <algorithm>

void fillVector(std::vector<uint32_t>& income) {

    income.clear();

    for (int i = 0; i < 10; ++i)
        income.push_back(rand() % 1001 - 500);

}

int main()
{
    srand(time(NULL));
    std::vector<uint32_t> vect;

    Stat stat;

    fillVector(vect);

    stat = std::for_each(vect.begin(), vect.end(), stat);

    /*for (auto elem : vect)
        stat(elem);*/

    stat.getStatics();


}
