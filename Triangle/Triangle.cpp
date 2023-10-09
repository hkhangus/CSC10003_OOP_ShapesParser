// Circle.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Triangle.h"


Triangle::Triangle(double a, double b, double c) {
	_a = a;
	_b = b;
	_c = c;
}

bool Triangle::isValid() {
	if (_a + _b <= _c || _a + _c <= _b || _b + _c <= _a)
		return false;
	else
		return true;
}

vector<double> Triangle::getAttribute() {
	vector<double> res;
	res.push_back(_a);
	res.push_back(_b);
	res.push_back(_c);
	return res;
}

double Triangle::chuvi() {
	if (!Triangle::isValid()) {
		return 0;
	}
	double res = _a + _b + _c;
	return res;
}

double Triangle::dientich() {
	if (!Triangle::isValid()) {
		return 0;
	}
	double p = this->chuvi() / 2;

	double res = p * (p - _a) * (p - _b) * (p - _c);
	res = sqrt(res);
	return res;
}