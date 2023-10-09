#pragma once
#include "Circle.h"


class CIRCLE_API CircleParser : public IParser
{
//singleton
private:
	inline static shared_ptr<CircleParser> instanceCircleParser = nullptr;
	CircleParser() {};
public:
	//huỷ các hàm tạo copy
	CircleParser(const CircleParser&) = delete;
	void operator=(const CircleParser&) = delete;
	//tạo và lấy instance
	static shared_ptr<CircleParser> getInstanceCircleParser() {
		if (instanceCircleParser == nullptr) {
			instanceCircleParser.reset(new CircleParser());
		}
		return instanceCircleParser;
	}
	shared_ptr<Shape> parse(stringstream data);
};