#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

#include "IParser.h"

using std::string;
using std::map;
using std::shared_ptr, std::make_shared;

class ParserFactory {
private:
	map<string, shared_ptr<IParser>> _prototypes; //lưu trữ parser dựa theo loại hình.
public:
	void registerWith(string type, shared_ptr<IParser> parser); //đăng kí parser
	~ParserFactory() = default;
public:
	shared_ptr<IParser> select(string type); //chọn parser đúng với loại hình
	//string toString() { return "Parse Factory"; };
};