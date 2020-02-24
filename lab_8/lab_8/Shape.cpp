
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
int Shape::getX() { return x; }
int Shape::getY(){ return y; }

std::pair<int, int> Shape::getXY(){
	return std::make_pair(x, y);
}


bool Shape::isMoreLeft(Shape &income) {
	return this->x < income.x;
}

bool Shape::isMoreUpper(Shape &income) {
	return this->y > income.x;
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
	return sh1->getX() > sh2->getX();
}

bool rightToLeft(Shape& sh1, Shape& sh2) {
	return sh1.getX() < sh2.getX();
}

bool topToBottom(Shape* sh1, Shape* sh2) {
	return sh1->getY() > sh2->getY();
}

bool bottomToTop(Shape* sh1, Shape* sh2) {
	return sh1->getY() < sh2->getY();
}