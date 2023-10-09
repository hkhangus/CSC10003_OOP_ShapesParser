
#include "pch.h"
#include "framework.h"
#include "RhombusParser.h"

shared_ptr<Shape> RhombusParser::parse(stringstream data) {
	string buffer;
	getline(data, buffer);
	regex aPattern("( d1=)\?([0-9]*[.])?[0-9]+\(, d2=)\?([0-9]*[.])?[0-9]+"); //format chuẩn: d1=num, d2=num/với num có thể là thập phân
	bool matched = regex_match(buffer, aPattern);
	if (matched) {
		getline(data, buffer, ','); //lấy d1 trước dấu ,
		buffer = buffer.substr(buffer.find("=") + 1); //lấy số liệu sau =
		double d1 = stod(buffer); //chuyển hoá chuỗi thành số
		getline(data, buffer); //tương tự với d2
		buffer = buffer.substr(buffer.find("=") + 1);
		double d2 = stod(buffer);
		shared_ptr<Shape> res = make_shared<Rhombus>(d1, d2); //tạo object hình thoi
		return res;
	}
	else {
		return nullptr;
	}
}

shared_ptr<IParser> getParser() {
	//return make_shared<RhombusParser>();
	return RhombusParser::getInstanceRhombusParser();
}