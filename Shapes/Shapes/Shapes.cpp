#include <cassert>
#include <math.h>
#include <iostream>
#include <string>

class __declspec(dllexport) Point
{
private:
	double x;
	double y;
	double z;
public:
	Point() { x = 0; y = 0; z = 0; }
	Point setCoord(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	};
	double getX() { return this->x; }
	double getY() { return this->y; }
	double getZ() { return this->z; }
};

class __declspec(dllexport) Shape
{
protected:
	double r;
public:
	Shape() { r = 0; }
	void setRad(double R) { assert(R >= 0); this->r = R; };
	double getRad() { double tmp = this->r; return tmp; };
	virtual Point getPoint(double t) { return *(new Point()); };
	virtual Point getFirstDer(double t) { return *(new Point()); };
	virtual std::string getClassName() { return "Shape"; };
};

class __declspec(dllexport) Circle : public Shape
{
public:
	Circle() { r = 0; }
	virtual Point getPoint(double t) {
		return ((new Point())->setCoord(r * cos(t), r * sin(t), 0));
	};
	virtual Point getFirstDer(double t)
	{
		return ((new Point())->setCoord(-r * sin(t), r * cos(t), 0));
	};
	virtual std::string getClassName() { return "Circle"; };

};

class __declspec(dllexport) Ellipse : public Shape
{
private:
	double secR;
public:
	Ellipse() { r = 0; secR = 0; }
	void setRad(double fisrtRad, double secRad) {
		assert(fisrtRad >= 0 && secRad >= 0); this->r = fisrtRad; this->secR = secRad;
	};
	double getSecRad() { return this->secR; };
	virtual Point getPoint(double t) {
		return ((new Point())->setCoord(r * cos(t), secR * sin(t), 0));
	};
	virtual Point getFirstDer(double t) {
		return ((new Point())->setCoord(-r * sin(t), secR * cos(t), 0));
	};
	virtual std::string getClassName() { return "Ellips"; };
};



class __declspec(dllexport) Helix : public Shape
{
private:
	double step;
public:
	Helix() { r = 0; step = 0; }
	void setStep(double s) { this->step = s; }
	virtual Point getPoint(double t) {
		return ((new Point())->setCoord(r * cos(t), r * sin(t), step * t));
	};
	virtual Point getFirstDer(double t){
		return ((new Point())->setCoord(-r * sin(t), r * cos(t), step));
	};
	virtual std::string getClassName() { return "Helix"; };
};