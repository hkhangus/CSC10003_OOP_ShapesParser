
#include "pch.h"
#include "framework.h"
#include "TriangleParser.h"


shared_ptr<Shape> TriangleParser::parse(stringstream data) {
	string buffer;
	getline(data, buffer);
	regex aPattern("( a=)\?([0-9]*[.])?[0-9]+\(, b=)\?([0-9]*[.])?[0-9]+\(, c=)\?([0-9]*[.])?[0-9]+"); //format chuẩn a=num, b=num, c=num //num có thể là num.num
	bool matched = regex_match(buffer, aPattern);
	if (matched) {
		getline(data, buffer, ','); //lấy a=num
		buffer = buffer.substr(buffer.find("=") + 1); //tách num ra
		double a = stod(buffer); //chuyển num về số
		getline(data, buffer); //lấy b
		buffer = buffer.substr(buffer.find("=") + 1); //tương tự a
		double b = stod(buffer); 
		buffer = buffer.substr(buffer.find("=") + 1); //tương tự c
		double c = stod(buffer);
		shared_ptr<Shape> res = make_shared<Triangle>(a, b, c); //tạo object triangle
		return res;
	}
	else {
		return nullptr;
	}
}

shared_ptr<IParser> getParser() {
	return TriangleParser::getInstanceTriangleParser();
}