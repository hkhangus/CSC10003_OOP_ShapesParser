#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "IShapeToStringConverter.h"

using std::string;
using std::map;

class StringConverterStrategy {
private:
	map<string, shared_ptr<IShapeToStringConverter>> _prototypes; //lưu trữ converter ứng với tên class
public:
	~StringConverterStrategy() = default;
	void registerWith(string type, shared_ptr<IShapeToStringConverter> converter); //đăng kí converter cho strategy
public:
	shared_ptr<IShapeToStringConverter> set_strategy(string type); //chọn ra converter phù hợp
	//string toString() { return "Parse Factory"; };
};