
#include "pch.h"
#include "framework.h"
#include "CircleParser.h"

//// Square Parser ////
shared_ptr<Shape> CircleParser::parse(stringstream data) {
	string buffer;
	getline(data, buffer);
	regex aPattern("( r=)\?([0-9]*[.])?[0-9]+"); //format chuẩn r=num.num/r=num
	bool matched = regex_match(buffer, aPattern);
	if (matched) { //nếu đúng format thì lấy số liệu
		buffer = buffer.substr(buffer.find("=") + 1); //lấy số liệu sau =
		double r = stod(buffer); //convert số thực
		shared_ptr<Shape> res = make_shared<Circle>(r); //tạo object circle với r
		return res;
	}
	else {
		return nullptr;
	}
}

shared_ptr<IParser> getParser() {
	return CircleParser::getInstanceCircleParser();
}