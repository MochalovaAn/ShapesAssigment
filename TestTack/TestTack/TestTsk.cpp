#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <cstdlib>
#include <math.h>
#include "../../Shapes/Shapes/Shapes.h"

std::list <std::shared_ptr<Shape>>* createRandList() {
	std::list <std::shared_ptr<Shape>>* res = new std::list<std::shared_ptr<Shape>>();
	srand(time(NULL));

	//The container size was not specified in the assigment.
	//The value 10 is chosen for the convenience of checking the correctness of the program.
	for (int i = 0; i < 10; i++)
	{
		switch (rand() % 3 + 1) {
		case 1: {
			Circle* circle = new Circle();
			circle->setRad(rand());
			res->push_back(std::make_shared<Circle>(*circle));
			break; }
		case 2: {
			Ellipse* ellipse = new Ellipse();
			ellipse->setRad(rand(), rand());
			res->push_back(std::make_shared<Ellipse>(*ellipse));
			break; }
		case 3: {
			Helix* helix = new Helix();
			helix->setRad(rand());
			helix->setStep(rand());
			res->push_back(std::make_shared<Helix>(*helix));
			break;
		}
		}
	}
	return res;
}

void Compute(Shape* Shape, double t)
{
	auto point = Shape->getPoint(M_PI / 4);
	auto firstDer = Shape->getFirstDer(M_PI / 4);
	std::cout << "Coord (" << point.getX() << ", " << point.getY()
			  << ", " << point.getZ() << ")" << std::endl;
	std::cout << "Vector first der. (" << firstDer.getX() << ", "
			  << firstDer.getY() << ", " << firstDer.getZ() << ")" << std::endl;
	std::cout << std::endl;
}

void printShapeList(std::list <std::shared_ptr<Shape>>* shapeList) {
	std::list <std::shared_ptr<Shape>> ::iterator it;
	for (it = shapeList->begin(); it != shapeList->end(); ++it)
	{
		std::cout << it->get() << ' ' << it->get()->getClassName() 
				  << " with rad " << it->get()->getRad() << std::endl;
	}
	std::cout << std::endl;
}

bool compare(std::shared_ptr<Shape> a, std::shared_ptr<Shape> b) {
	return a.get()->getRad() < b.get()->getRad();
}

int main() {
	// second point of the assignment
	std::list <std::shared_ptr<Shape>>* shapeList = createRandList();
	printShapeList(shapeList);

	// third point of the assignment
	std::list <std::shared_ptr<Shape>> ::iterator it;
	for (it = shapeList->begin(); it != shapeList->end(); ++it)
	{
		Compute(it->get(), M_PI / 4);
	}


	// fourth point of the assignment
	std::list <std::shared_ptr<Shape>>* secList = new std::list<std::shared_ptr<Shape>>();
	for (it = shapeList->begin(); it != shapeList->end(); ++it)
	{
		if (it->get()->getClassName() == "Circle") {
			secList->push_back(*it);
		}
	}

	// fifth point of the assignment
	secList->sort(compare);
	printShapeList(secList);

	// sixth point of the assignment
	double sum = 0;
	for (it = shapeList->begin(); it != shapeList->end(); ++it)
	{
		sum += it->get()->getRad();
	}
	std::cout << "Total sum of radii of all curves is " << sum << std::endl;
	std::cout << std::endl;

	//Visual check unit. 
	//If the second container contains objects from the first,
	//then the radius of the object from the source will change too.
	for (it = secList->begin(); it != secList->end(); ++it)
	{
		it->get()->setRad(777);
	}
	printShapeList(shapeList);
	printShapeList(secList);

	system("pause");

};