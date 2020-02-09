// Lab1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <iterator>

using namespace std;



int main() {

    int in_ch;
    vector<int> input;
    while (true) {

        cin >> in_ch;
        if (in_ch == 0) break;
        input.push_back(in_ch);

    }

    if (input.back() == 1) {
        for (vector<int>::iterator i = input.begin(); i != input.end();)
            if (*i % 2 == 0)
                i = input.erase(i);
            else i++;

    } else if (input.back() == 2) {
        for (vector<int>::iterator i = input.begin(); i != input.end() - 1; i++)
            if (*i % 3 == 0) {
                i = input.insert(i + 1, 3, 1);
            }
    }

    for (vector<int>::iterator i = input.begin(); i != input.end(); i++)
        cout << *i << " ";


}

