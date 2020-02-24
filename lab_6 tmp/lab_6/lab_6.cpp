// lab_6.cpp : by BadDragon
//



#include <iostream>
#include "Header.h"
#include <vector>
#include <conio.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{    

    vector<string> vect;
    readFile(vect);

    for (auto elem : vect)
        cout << elem << " ";


    cout << endl;
    cout << "-------Second task-------" << endl;

    srand(time(NULL));

    vector<Shape> shapes;


    fill(shapes, 10);
    cout << "-------- first fill" << endl;
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
