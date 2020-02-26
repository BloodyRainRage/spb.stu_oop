#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include <utility>
#include <string>
#include <iostream>

double fill();
void printVect(double&);
double mult(double&);

//-------Task2-------//
class Shape {

protected:
	int x, y;
	std::string name;

public:
	virtual void Draw()=0;
	bool isMoreLeft(Shape*);
	bool isMoreUpper(Shape*);

	int getX();
	int getY();

	std::pair<int, int> getXY();

};


class Triangle : public Shape {

public:
	Triangle(int, int);

	virtual void Draw() override;

};

class Circle : public Shape {

public:
	Circle(int, int);

	virtual void Draw() override;

};


class Square : public Shape {

public:
	Square(int, int);

	virtual void Draw() override;

};


bool leftToRight(Shape* sh1, Shape* sh2);
bool rightToLeft(Shape* sh1, Shape* sh2);

bool topToBottom(Shape* sh1, Shape* sh2);
bool bottomToTop(Shape* sh1, Shape* sh2);

#endif // !SHAPE_H