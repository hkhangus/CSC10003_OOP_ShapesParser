
#include "pch.h"
#include "framework.h"
#include "RectangleParser.h"

shared_ptr<Shape> RectangleParser::parse(stringstream data) {
	string buffer;
	getline(data, buffer);
	regex aPattern("( w=)\?([0-9]*[.])?[0-9]+\(, h=)\?([0-9]*[.])?[0-9]+"); //format chuẩn w=num, h=num //num có thể là num.num
	bool matched = regex_match(buffer, aPattern);
	if (matched) { //chuẩn format thì lấy số liệu
		getline(data, buffer, ','); //lấy w=num trước dấu ,
		buffer = buffer.substr(buffer.find("=") + 1); //lấy num sau w
		double w = stod(buffer); //convert về số
		getline(data, buffer);  //tương tự w
		buffer = buffer.substr(buffer.find("=") + 1);
		double h = stod(buffer);
		shared_ptr<Shape> res = make_shared<RRectangle>(w, h); //tạo object Rectangle với 2 số liệu w,h
		return res;
	}
	else {
		return nullptr;
	}
}

shared_ptr<IParser> getParser() {
	return RectangleParser::getInstanceRectangleParser();
}