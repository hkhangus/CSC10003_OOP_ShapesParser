#pragma once
#include "Rectangle.h"


class RECTANGLE_API RectangleParser : public IParser
{
//singleton
private:
	inline static shared_ptr<RectangleParser> instanceRectangleParser = nullptr;
	RectangleParser() {};
public:
	//ngặn chặn các thao tác tạo copy
	RectangleParser(const RectangleParser&) = delete;
	void operator=(const RectangleParser&) = delete;
	//tạo và lấy instance
	static shared_ptr<RectangleParser> getInstanceRectangleParser() {
		if (instanceRectangleParser == nullptr) {
			instanceRectangleParser.reset(new RectangleParser());
		}
		return instanceRectangleParser;
	}
	shared_ptr<Shape> parse(stringstream data);
};