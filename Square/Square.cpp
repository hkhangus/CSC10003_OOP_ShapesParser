#include "pch.h"
#include "framework.h"
#include "Square.h"

////Square class////
Square::Square(double a) {
	_a = a;
}

vector<double> Square::getAttribute() { //trả về cạnh của hình
	vector<double> res;
	res.push_back(_a);
	return res;
}

double Square::chuvi() { //chu vi hình vuông = cạnhx4
	double res = _a * 4;
	return res;
}

double Square::dientich() { //diện tích hình vuông bằng cạnhxcạnh
	double res = _a * _a;
	return res;
}