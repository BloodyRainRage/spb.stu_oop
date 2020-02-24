// lab_5.cpp : by BadDragon
//

/*1.	Написать программа, которая выполняет следующие действия:

a.	Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2, генерируются случайным образом в диапазоне от -5 до 5, str заполняется из таблицы (таблица содержит 10 произвольных строк, индекс строки генерируется случайным образом)
b.	Выводит полученный вектор на печать
c.	Сортирует вектор следующим образом:
i.	По возрастанию key1
ii.	Если key1 одинаковые, то по возрастанию key2
iii.	Если key1 и key2 одинаковые, то по возрастанию длинны строки str
d.	Выводит полученный вектор на печать

DataStruct определена следующим образом:
typedef struct
{
    int       key1;
    int       key2;
    string  str;
} DataStruct;
*/

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
