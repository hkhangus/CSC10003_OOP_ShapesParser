#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <sstream>

#include "Shape.h"
#include "Object.h"

using std::string;
using std::wstring;
using std::wstringstream;
using std::setw, std::setfill, std::left;
using std::fixed, std::setprecision;
using std::shared_ptr, std::make_shared;

//INTERFACE Converter
class IShapeToStringConverter //: public Object 
{
protected:
	int space = 25; //khoảng cách giữa hai | |
public:
	//virtual ~IShapeToStringConverter() = default;
	virtual wstring convertData(shared_ptr<Shape>) = 0; //convert string chỉ những dữ liệu của hình
	virtual wstring convertDataCVDT(shared_ptr<Shape>) = 0; //covert string bao gồm chu vi diện tích
	string toString() { return "ConverterShape"; }
};