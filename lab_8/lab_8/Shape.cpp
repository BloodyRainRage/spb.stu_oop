
#define _USE_MATH_DEFINES
#include <math.h>
#include "Shape.h"

double fill() {
	return rand() *0.1;
}

void printVect(double& d) {
	std::cout << d << " ";
}

double mult(double& d) {
	return d *= M_PI;
}



//-------Task2-------//
int Shape::getX() { return this->x; }
int Shape::getY(){ return this->y; }

std::pair<int, int> Shape::getXY(){
	return std::make_pair(x, y);
}


bool Shape::isMoreLeft(Shape *income) {
	return this->x < income->getX();
}

bool Shape::isMoreUpper(Shape *income) {
	return this->y > income->getY();
}

Triangle::Triangle(int x, int y) {	
	this->x = x;
	this->y = y;
	this->name = "triangle";
}

void Triangle::Draw() {
	std::cout << std::endl << "Shape: " << this->name << std::endl;
	std::cout << "position: {" << this->x << ", " << this->y << "};";
}

Circle::Circle(int x, int y) {
	this->x = x;
	this->y = y;
	this->name = "circle";
}

void Circle::Draw() {
	std::cout << std::endl << "Shape: " << this->name << std::endl;
	std::cout << "position: {" << this->x << ", " << this->y << "};";
}


Square::Square(int p, int q) {
	this->x = p;
	this->y = q;
	this->name = "square";
}
void Square::Draw() {
	std::cout << std::endl << "Shape: " << this->name << std::endl;
	std::cout << "position: {" << this->x << ", " << this->y << "};";
}


bool leftToRight(Shape* sh1, Shape* sh2) {
	return sh1->isMoreLeft(sh2);
}

bool rightToLeft(Shape* sh1, Shape* sh2) {
	return !(sh1->isMoreLeft(sh2));
}

bool topToBottom(Shape* sh1, Shape* sh2) {
	return sh1->isMoreUpper(sh2);
}

bool bottomToTop(Shape* sh1, Shape* sh2) {
	return sh2->isMoreUpper(sh1);
}