// lab_8.cpp : by BadDragon
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include "Shape.h"
using namespace std;

int main()
{
    srand(time(NULL));
    vector<double> vect(10);
    
    generate(vect.begin(), vect.end(), fill);

    for_each(vect.begin(), vect.end(), printVect);

    for_each(vect.begin(), vect.end(), mult);
    cout << endl;
    for_each(vect.begin(), vect.end(), printVect);

    cout << endl << endl << "-------Task2-------";


    vector<Shape*> shapes;

    for (int i = 0; i < 10; ++i) {
        switch (rand()%3){
        case 0: shapes.push_back(new Triangle(rand()%11-5, rand() % 11 - 5));
            break;
        case 1: shapes.push_back(new Circle(rand() % 11 - 5, rand() % 11 - 5));
            break;
        case 2: shapes.push_back(new Square(rand() % 11 - 5, rand() % 11 - 5));
            break;
        
        default:
            break;
        }
    }

    for (auto elem : shapes)
        elem->Draw();

    cout << endl << endl << "left to right" << endl;
    sort(shapes.begin(), shapes.end(), leftToRight);

    for (auto elem : shapes)
        elem->Draw();

    cout << endl << endl << "right to left" << endl;
    sort(shapes.begin(), shapes.end(), leftToRight);
    
    for (auto elem : shapes)
        elem->Draw();
    
    cout << endl << endl << "top to bottom" << endl;
    sort(shapes.begin(), shapes.end(), topToBottom);

    for (auto elem : shapes)
        elem->Draw();
    
    cout << endl << endl << "bottom to top" << endl;
    sort(shapes.begin(), shapes.end(), bottomToTop);

    for (auto elem : shapes)
        elem->Draw();
}


/*1.	Разработать программу, которая, используя только стандартные алгоритмы и функторы, 
умножает каждый элемент списка чисел с плавающей  точкой на число PI
2.	Разработать программу, которая:
a.Реализует иерархию геометрических фигур состоящую из :
i.Класс Shape.
1.	Содержит информацию о положении центра фигуры(координаты x и y).
2.	Содердит метод IsMoreLeft, позволяющий определить расположена ли данная фигура левее(определяется по положению центра) 
чем фигура переданная в качестве аргумента
3.	Содердит метод IsUpper, позволяющий определить расположена ли данная фигура выше(определяется по положению центра) 
чем фигура переданная в качестве аргумента
4.	Определяет чисто виртаульную функцию рисования Draw(каждая фигура в реализации этой функци должна выводить на 
стандартный вывод свое название и положение цента)
ii.Класс Circle производный от класса Shape
1.	Реализует Draw
iii.Класс Triangle производный от класса Shape
1.	Реализует Draw
iv.Класс Square производный от класса Shape
1.	Реализует Draw

b.Содержит список list<Shape*>, заполенный указателями на различные фигуры

c.С помощью стандартных алгоритмов и адаптеров выводит(Draw) все фигуры

d.С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра слева - направо(имется в виду, что в 
начале списка должны идти фигуры находящиеся левее, координата x) и выводит фигуры(Draw)

e.С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра справа - налево и выводит фигуры

f.С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра сверху - вниз и выводит фигуры

g.С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра снизу - вверх и выводит фигуры

*/
