// Rhombus.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Rhombus.h"


Rhombus::Rhombus(double d1, double d2) {
	_d1 = d1;
	_d2 = d2;
}

vector<double> Rhombus::getAttribute() {
	vector<double> res;
	res.push_back(_d1);
	res.push_back(_d2);
	return res;
}

double Rhombus::chuvi() {
	double res = sqrt(_d1 * _d1 + _d2 * _d2);
	res *= 2;
	return res;
}

double Rhombus::dientich() {
	return _d1 * _d2 / 2;
}