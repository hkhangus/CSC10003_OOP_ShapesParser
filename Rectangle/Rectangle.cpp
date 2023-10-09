// Rectangle.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Rectangle.h"


RRectangle::RRectangle(double w, double h) {
	_w = w;
	_h = h;
}

vector<double> RRectangle::getAttribute() {
	vector<double> res;
	res.push_back(_w);
	res.push_back(_h);
	return res;
}

double RRectangle::chuvi() {
	return (_w + _h) * 2;
}

double RRectangle::dientich() {
	return _w * _h;
}