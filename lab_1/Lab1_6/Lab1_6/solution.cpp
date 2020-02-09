// Lab1_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
 
#include <iostream>
#include "Source.h"
#include <vector>
#define d vector<double>
#define m void merge(d &vect5, d &vect10, d &vect25, d &vect50, d &vect100)
#define f void fill(d &vect5, d &vect10, d &vect25, d &vect50, d &vect100)
#define p void print(d &vect5, d &vect10, d &vect25, d &vect50, d &vect100)
#define г int main()


using namespace std;
 
m {
    mergeSort(vect5, 0, vect5.size());
    mergeSort(vect10, 0, vect10.size());
    mergeSort(vect25, 0, vect25.size());
    mergeSort(vect50, 0, vect50.size());
    mergeSort(vect100, 0, vect100.size());
}
 
f {
    fillRandom(&vect5[0], vect5.size());
    fillRandom(&vect10[0], vect10.size());
    fillRandom(&vect25[0], vect25.size());
    fillRandom(&vect50[0], vect50.size());
    fillRandom(&vect100[0], vect100.size());
}
 
p {
    cout << endl;
    for (int i = 0; i < vect5.size(); i++)
        cout << vect5[i] << " ";
 
    cout << endl;
    for (int i = 0; i < vect10.size(); i++)
        cout << vect10[i] << " ";
 
    cout << endl;
    for (int i = 0; i < vect25.size(); i++)
        cout << vect25[i] << " ";
    cout << endl;
 
    for (int i = 0; i < vect50.size(); i++)
        cout << vect50[i] << " ";
    cout << endl;
 
    for (int i = 0; i < vect100.size(); i++)
        cout << vect100[i] << " ";
}
 
 
г{
    d vect5(5), vect10(10), vect25(25), vect50(50), vect100(100);
 
    fill(vect5, vect10, vect25, vect50, vect100);
    merge(vect5, vect10, vect25, vect50, vect100);
    print(vect5, vect10, vect25, vect50, vect100);
    return 0;
}