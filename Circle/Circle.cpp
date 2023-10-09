// Circle.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Circle.h"


Circle::Circle(double r) {
	_r = r;
}

vector<double> Circle::getAttribute() {
	vector<double> res;
	res.push_back(_r);
	return res;
}

double Circle::chuvi() {
	double res = _r * 2 * 3.14;
	return res;
}

double Circle::dientich() {
	double res = _r * _r * 3.14;
	return res;
}