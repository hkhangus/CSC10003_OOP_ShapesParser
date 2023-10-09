#pragma once
#include "Square.h"

class SQUARE_API SquareParser : public IParser
{
private:
	inline static shared_ptr<SquareParser> instanceSquareParser = nullptr;
	SquareParser() {};
public:
	SquareParser(const SquareParser&) = delete;
	void operator=(const SquareParser&) = delete;
	static shared_ptr<SquareParser> getInstanceSquareParser() {
		if (instanceSquareParser == nullptr) {
			instanceSquareParser.reset(new SquareParser());
		}
		return instanceSquareParser;
	}
	shared_ptr<Shape> parse(stringstream data);
};