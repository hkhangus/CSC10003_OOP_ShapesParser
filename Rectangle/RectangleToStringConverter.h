#pragma once
#include "Rectangle.h"

class RECTANGLE_API RectangleToStringConverter : public IShapeToStringConverter
{
//singleton
private:
	inline static shared_ptr<RectangleToStringConverter> instanceRectangleToStringConverter = nullptr;
	RectangleToStringConverter() {};
public:
//ngăn chặn các thao tác copy
	RectangleToStringConverter(const RectangleToStringConverter&) = delete;
	void operator=(const RectangleToStringConverter&) = delete;
	//tạo và lấy instance
	static shared_ptr<RectangleToStringConverter> getInstanceRectangleToStringConverter() {
		if (instanceRectangleToStringConverter == nullptr) {
			instanceRectangleToStringConverter.reset(new RectangleToStringConverter());
		}
		return instanceRectangleToStringConverter;
	}
	wstring convertData(shared_ptr<Shape>);
	wstring convertDataCVDT(shared_ptr<Shape>);
};