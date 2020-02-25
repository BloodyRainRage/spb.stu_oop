#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <vector>
#include <fstream>

//reading table from file
void readFile(std::vector<std::string>&);
//check if should element be added
bool isContained(std::vector<std::string>&, std::string);


//-------Second task-------//
struct Point {
	int x, y;
};

struct Shape {
	int vertex_num = 0;
	std::vector<Point> vertexes;
	std::string name;
};


//returns a triangle
Shape add(Point, Point, Point);

//returns a quadrangle
Shape add(Point, Point, Point, Point);

//returns a pentagon
Shape add(Point, Point, Point, Point, Point);

//calculates distance between two points
int distSq(Point p, Point q);

//checkes if shape is a square
bool isSquare(Point p1, Point p2, Point p3, Point p4);

//checkes if shape is a rectangle
bool isRectangle(Point p1, Point p2, Point p3, Point p4);

//creates a random point in range of -5:5
Point createRandomPoint();

//creates random shape
Shape addRandom();

//fills the vector with shapes
void fill(std::vector<Shape>&, int);

//printing a vector of shapes
void print(Shape const&);

//print a point
void printPoint(Point const& p);

//returns a random point from a shape
Point getRandomPoint(Shape &);


bool vert_num_is_5(Shape& s);
bool vert_num_is_3(Shape& s);
bool vert_num_is_4(Shape& s);

bool _isSquare(Shape& s);
bool _isRectangle(Shape& s);

//predicate for sorting
bool sortShapes(Shape&, Shape&);
#endif // !HEADER_H

