#pragma once
#include "Triangle.h"


class TRIANGLE_API TriangleParser : public IParser
{
//singleton
private:
	inline static shared_ptr<TriangleParser> instanceTriangleParser = nullptr;
	TriangleParser() {};
public:
	//ngăn chặn các thao tác copy
	TriangleParser(const TriangleParser&) = delete;
	void operator=(const TriangleParser&) = delete;
	//tạo và lấy instance
	static shared_ptr<TriangleParser> getInstanceTriangleParser() {
		if (instanceTriangleParser == nullptr) {
			instanceTriangleParser.reset(new TriangleParser());
		}
		return instanceTriangleParser;
	}
	shared_ptr<Shape> parse(stringstream data);
};