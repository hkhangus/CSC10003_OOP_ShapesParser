#pragma once
#include "Square.h"

class SQUARE_API SquareToStringConverter : public IShapeToStringConverter {
private: //phục vụ cho singleton
	inline static shared_ptr<SquareToStringConverter> instanceSquareToStringConverter = nullptr;
	SquareToStringConverter() {};
public:
	//ngăn hành vi tạo copy
	SquareToStringConverter(const SquareToStringConverter&) = delete;
	void operator=(const SquareToStringConverter&) = delete;
	//lấy instance của class
	static shared_ptr<SquareToStringConverter> getInstanceSquareToStringConverter() {
		if (instanceSquareToStringConverter == nullptr) {
			instanceSquareToStringConverter.reset(new SquareToStringConverter());
		}
		return instanceSquareToStringConverter;
	}
	wstring convertData(shared_ptr<Shape>);
	wstring convertDataCVDT(shared_ptr<Shape>);
};