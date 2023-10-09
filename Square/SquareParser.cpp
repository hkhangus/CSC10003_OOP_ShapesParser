
#include "pch.h"
#include "framework.h"
#include "SquareParser.h"

shared_ptr<Shape> SquareParser::parse(stringstream data) {
	string buffer;
	getline(data, buffer);
	regex aPattern("( a=)\?([0-9]*[.])?[0-9]+"); //format hợp lệ: a=num/ a=num.num
	bool matched = regex_match(buffer, aPattern);
	if (matched) { //đúng format thì lấy số liệu
		buffer = buffer.substr(buffer.find("=") + 1); //lấy chuỗi sau dấu = chính là số liêu
		double a = stod(buffer); //covert về double
		shared_ptr<Shape> res = make_shared<Square>(a); //tạo square
		return res;
	}
	else { //sai format không thể tạo hình vuông
		return nullptr;
	}
}

shared_ptr<IParser> getParser() {
	//return make_shared<SquareParser>();
	return SquareParser::getInstanceSquareParser();
}