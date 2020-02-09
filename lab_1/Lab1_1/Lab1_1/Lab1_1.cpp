// Lab1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <iterator>
#include "MergeSort.h"

using namespace std;



int main(){
    
    vector<int> vect;
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
        vect.push_back(rand() % 10);

    /*for (int i = 0; i < 10; i++)
        cout << vect[i] << " ";*/

    vector<int> vect2(vect);
    vector<int> vect3(vect);

    cout << endl << "1_1: " << endl;
    clock_t start = clock();
    mergeSort_operator(vect, 0, vect.size());
    clock_t end = clock();
    double sec = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time: " << sec << endl;
    /*for (vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
        cout << *i << " ";*/


    cout << endl << "1_2: " << endl;
    start = clock();
    mergeSort_at(vect2, 0, vect.size());
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time: " << sec << endl;
    /*for (vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
        cout << *i << " ";*/


    cout << endl << "1_3: " << endl;
    start = clock();
    bubbleSort(vect3, 0, vect.size());
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time: " << sec << endl;
   /* for (vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
        cout << *i << " ";*/
    
    cout << endl;
    

}

