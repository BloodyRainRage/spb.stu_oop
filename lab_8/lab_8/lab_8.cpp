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
