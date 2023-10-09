#pragma once
#include "Rhombus.h"


class RHOMBUS_API RhombusParser : public IParser
{
private: //phục vụ singleton
	inline static shared_ptr<RhombusParser> instanceRhombusParser = nullptr;
	RhombusParser() {};
public:
	//ngăn chặn các khả năng tạo nhiều instance 
	RhombusParser(const RhombusParser&) = delete;
	void operator=(const RhombusParser&) = delete;
	//tạo 1 instance duy nhất và lấy ra
	static shared_ptr<RhombusParser> getInstanceRhombusParser() {
		if (instanceRhombusParser == nullptr) {
			instanceRhombusParser.reset(new RhombusParser());
		}
		return instanceRhombusParser;
	}
	shared_ptr<Shape> parse(stringstream data);
};