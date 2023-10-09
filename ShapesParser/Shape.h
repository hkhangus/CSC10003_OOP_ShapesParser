#pragma once
#include <vector>
#include <string>

using std::vector;

//Shape INTERFACE
class Shape {
public:
	virtual vector<double> getAttribute() = 0; //lấy các thuộc tính của hình kế thừa
	virtual double chuvi() = 0; //tính chu vi
	virtual double dientich() = 0; //tính diện tích
};