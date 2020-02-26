#include "Header.h"
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void readFile(vector<string> &resultVector) {

	ifstream input;
	input.open("lab_6.cpp");
	
	string word;


	while (input >> word){
		if (isContained(resultVector, word)) {
			//not necessary. It replaces any punctuation sight
			/*auto q = unique(word.begin(), word.end(), [](unsigned char l, unsigned char r) {
				return ispunct(l) && ispunct(r);
			});
			word = word + " ";
			for (auto it = word.begin(); it != word.end(); ++it) {

				if (ispunct(*it)) {

					it = word.erase(it);

				}
			}
			string temp;
			for (int i = 0; i < word.length() - 1; ++i)
				temp += word[i];

				*/
			resultVector.push_back(word);
		}
	}	

}

bool isContained(vector<string>& vect, string str) {

	for (auto elem : vect)
		if (elem == str) return false;
	
	return true;

}


//-------Second task-------//

Shape add(Point a, Point b, Point c) {
	Shape shape;
	shape.vertex_num = 3;
	shape.vertexes.push_back(a);
	shape.vertexes.push_back(b);
	shape.vertexes.push_back(c);

	shape.name = "triangle";

	return shape;
}

Shape add(Point a, Point b, Point c, Point d) {

	Shape shape;

	if (isSquare(a, b, c, d))
		shape.name = "square";
	else if (isRectangle(a, b, c, d))
		shape.name = "rectangle";
	else shape.name = "quadrangle";

	shape.vertex_num = 4;
	shape.vertexes.push_back(a);
	shape.vertexes.push_back(b);
	shape.vertexes.push_back(c);
	shape.vertexes.push_back(d);
	
	return shape;
}


int distSq(Point p, Point q) {
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}


bool isSquare(Point p1, Point p2, Point p3, Point p4) {
	int d2 = distSq(p1, p2); // from p1 to p2 
	int d3 = distSq(p1, p3); // from p1 to p3 
	int d4 = distSq(p1, p4); // from p1 to p4 

	// If lengths if (p1, p2) and (p1, p3) are same, then 
	// following conditions must met to form a square. 
	// 1) Square of length of (p1, p4) is same as twice 
	// the square of (p1, p2) 
	// 2) Square of length of (p2, p3) is same 
	// as twice the square of (p2, p4) 

	if (d2 == d3 && 2 * d2 == d4
		&& 2 * distSq(p2, p4) == distSq(p2, p3)) {
		return true;
	}

	// The below two cases are similar to above case 
	if (d3 == d4 && 2 * d3 == d2
		&& 2 * distSq(p3, p2) == distSq(p3, p4)) {
		return true;
	}
	if (d2 == d4 && 2 * d2 == d3
		&& 2 * distSq(p2, p3) == distSq(p2, p4)) {
		return true;
	}

	return false;
}


bool isRectangle(Point p1, Point p2, Point p3, Point p4) {
	int d1 = distSq(p1, p2);
	int d2 = distSq(p4, p3); 
	int d3 = distSq(p2, p3); 
	int d4 = distSq(p1, p4); 


	//if distances of parallel lines are equal
	//the shape is a rectangle

	if (d1 == d2 && d3 == d4)
		return true;

	if (d1 == d3 && d2 == d4)
		return true;

	if (d1 == d4 && d2 == d3)
		return true;
	

	return false;
}

Point createRandomPoint() {
	Point p;

	p.x = rand() % 11 - 5;
	p.y = rand() % 11 - 5;

	return p;
}

void fill(vector<Shape>& income, int amount) {
	
	for(int i = 0; i < amount; ++i) {
		income.push_back(addRandom());
	}

}


Shape addRandom() {

	Shape sh;

	sh.vertex_num = rand() % 3 + 3;

	for (int i = 0; i < sh.vertex_num; ++i) {

		sh.vertexes.push_back(createRandomPoint());

	}

	if (sh.vertex_num == 4)
		if (isSquare(sh.vertexes[0], sh.vertexes[1], sh.vertexes[2], sh.vertexes[3]))
			sh.name = "square";
		else if (isRectangle(sh.vertexes[0], sh.vertexes[1], sh.vertexes[2], sh.vertexes[3]))
			sh.name = "rectangle";
		else sh.name = "quadrangle";
	else if (sh.vertex_num == 3) sh.name = "triangle";
	else sh.name = "pentagon";


	return sh;
}

void print(Shape const& income) {

	cout << endl;
	cout << "number of vertexes: " << income.vertex_num;
	cout << " | the shape is a " << income.name << ". " << endl;
	cout << "coordinates: ";
	for_each(income.vertexes.begin(), income.vertexes.end(), printPoint);	
}

void printPoint(Point const& p) {

	cout << "{" << p.x << ", " << p.y << "} ";

}


bool vert_num_is_5(Shape& s) { return (s.vertex_num == 5); }
bool vert_num_is_4(Shape& s) { return (s.vertex_num == 4); }
bool vert_num_is_3(Shape& s) { return (s.vertex_num == 3); }

bool _isSquare(Shape& s) { return s.name == "square"; }
bool _isRectangle(Shape& s) { return s.name == "rectangle"; }

Point getRandomPoint(Shape &sh) {
	return (sh.vertexes[rand() % (sh.vertex_num)]);
}

bool sortShapes(Shape& sh1, Shape& sh2) {

	if (sh2.vertex_num > sh1.vertex_num) return true;
	
	if (sh1.name == "square" && (sh2.name == "rectangle" || sh2.name == "quadrangle")) return true;

	return false;
}