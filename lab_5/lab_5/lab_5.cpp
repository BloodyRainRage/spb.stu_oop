// lab_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    ifstream input;
    input.open("resource.txt");
    vector<string> table;
    vector<DataStruct> ds;

    readFile(input, table);

    for (int i = 0; i < 30; ++i) {
        ds.push_back(fillStruct(table));
    }
    cout << "Vector before sort:";
    print(ds);

    sort(ds);
    
    cout << "Vector after sort:";
    print(ds);

    return 0;
}
