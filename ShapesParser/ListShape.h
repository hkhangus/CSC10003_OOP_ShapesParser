#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "StringConverterStrategy.h"
#include "Shape.h"

using std::wcout, std::endl;
using std::vector;
using std::string;
using std::shared_ptr, std::make_shared;

class ListShape
{
private:
	vector<shared_ptr<Shape>> _shapes; //lưu trữ shapes
	StringConverterStrategy _strategy; //strategy convert
public:
	ListShape(vector<shared_ptr<Shape>>&, StringConverterStrategy&); //constructor truyền shape và strategy cho 2 thuộc tính
	void printShape(); //in danh sách hình gồm thuộc tính.
	void sortAreaByAsc(); //sắp xếp dnah sách hình theo thứ tự tăng dần diện tích
	void printShapeComplete(); //in danh sách hình gồm chu vi, diện tích.
};

