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

    setlocale(LC_ALL, "Russian");
    char str[400], ch;
    int k = 0;
    ifstream in("input.txt");

    while (in) {
        in.get(ch);
        str[k] = ch;
        ++k;
    }
    for (int i = 0; i < k; ++i) {
        cout << str[i];
    }
    //copy str to vector in 
    vector<char> vecs(str, str + k);

    ostream_iterator<char> out_it(cout);
    copy(vecs.begin(), vecs.end(), out_it);

}

