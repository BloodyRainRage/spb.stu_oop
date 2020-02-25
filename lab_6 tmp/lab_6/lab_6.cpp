// lab_6.cpp : by BadDragon
//

/*1.	Написать программу, которая выполняет следующие действия :
a.Читает содержимое текстового файла
b.Выделяет слова, словом считаются последовательность символов разделенных пробелами и / или 
знаками табуляции и / или символами новой строки
c.Вывести список слов присутствующий в тексте без повторений(имеется в виду, что одно и то же 
слово может присутствовать в списке только один раз)

2.	Написать программу, которая выполняет следующие действия(все операции должны выполняться с 
помощью стандартных алгоритмов) :
    a.Заполняет вектор геометрическими фигурами.Геометрическая фигура может быть треугольником, 
        квадратом, прямоугольником или пяти угольником.Структура описывающая геометрическую фигуру  определена ниже,
    b.Подсчитывает общее количество вершин всех фигур содержащихся в векторе(так треугольник добавляет к 
        общему числу 3, квадрат 4 и т.д.)
    c.Подсчитывает количество треугольников, квадратов и прямоугольников в векторе
    d.Удаляет все пятиугольники
    e.На основании этого вектора создает vector<Point>, который содержит координаты одной из вершин(любой) каждой 
        фигуры, т.е.первый элемент этого вектора содержит координаты одной из вершину первой фигуры, второй элемент 
        этого вектора содержит координаты одной из вершину второй фигуры и т.д.
    f.Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом прямоугольники.
    g.Распечатывает вектор после каждого этапа работы
*/


#include <iostream>
#include "Header.h"
#include <vector>
#include <conio.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{    
    cout << "-------first task -------" << endl;
    vector<string> vect;
    readFile(vect);

    for (auto elem : vect)
        cout << elem << " ";


    cout << endl;
    cout << "-------Second task-------" << endl;

    srand(time(NULL));

    vector<Shape> shapes;
    
    cout << "-------- first fill" << endl;    

    fill(shapes, 10);
    Point p1 = { 10,20 };
    Point p2 = { 10,10 };
    Point p3 = { 20,20 };
    Point p4 = { 20,10 };

    shapes.push_back(add(p1, p2, p3, p4));
    for_each(shapes.begin(), shapes.end(), print);


    cout << endl << endl << "-------- amount of vertexes ";
    int count = 0;
    count += count_if(shapes.begin(), shapes.end(), vert_num_is_3) *3;
    count += count_if(shapes.begin(), shapes.end(), vert_num_is_4) *4;
    count += count_if(shapes.begin(), shapes.end(), vert_num_is_5) *5;
    
    
    cout << count;

    cout << endl << endl << "-------- amount of triangles, squares and rectangles: ";

    cout << endl << "amount of triangles: ";
    cout << count_if(shapes.begin(), shapes.end(), vert_num_is_3);
    cout << endl << "amount of squares: ";
    cout << count_if(shapes.begin(), shapes.end(), _isSquare);
    cout << endl << "amount of rectangles: ";
    cout << count_if(shapes.begin(), shapes.end(), _isRectangle);

    cout << endl << endl << "-------- removing pentagons";
    shapes.erase(remove_if(shapes.begin(), shapes.end(), vert_num_is_5), shapes.end());
    for_each(shapes.begin(), shapes.end(), print);
    
    cout << endl << endl << "-------- vector<Point> = ";
    vector<Point> points;
    points.resize(shapes.size());
    srand(time(NULL));
    transform(shapes.begin(), shapes.end(), points.begin(), getRandomPoint);

    for_each(points.begin(), points.end(), printPoint);

    cout << endl << endl << "-------- sorting";

    sort(shapes.begin(), shapes.end(), sortShapes);

    for_each(shapes.begin(), shapes.end(), print);

    return 0;
}
