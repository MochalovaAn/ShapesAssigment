#pragma once

#include <cassert>
#include <math.h>
#include <iostream>
#include <string>

class Point
{
private:
	double x;
	double y;
	double z;
public:
	Point();
	Point setCoord(double x, double y, double z);
	double getX();
	double getY();
	double getZ();
};

class Shape
{
protected:
	double r;
public:
	Shape();
	void setRad(double R);
	double getRad();
	virtual Point getPoint(double t);
	virtual Point getFirstDer(double t);
	virtual std::string getClassName();
};

class Circle : public Shape
{
public:
	Circle();
	virtual Point getPoint(double t);
	virtual Point getFirstDer(double t);
	virtual std::string getClassName();
};

class Ellipse : public Shape
{
private:
	double secR;
public:
	Ellipse();
	void setRad(double fisrtRad, double secRad);
	double getSecRad();
	virtual Point getPoint(double t);
	virtual Point getFirstDer(double t);
	virtual std::string getClassName();
};



class Helix : public Shape
{
private:
	double step;
public:
	Helix();
	void setStep(double s);
	virtual Point getPoint(double t);
	virtual Point getFirstDer(double t);
	virtual std::string getClassName();
};