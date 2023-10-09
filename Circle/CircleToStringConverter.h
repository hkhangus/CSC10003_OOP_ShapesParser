#pragma once
#include "Circle.h"

class CIRCLE_API CircleToStringConverter : public IShapeToStringConverter
{
//singleton
private:
	inline static shared_ptr<CircleToStringConverter> instanceCircleToStringConverter = nullptr;
	CircleToStringConverter() {};
public:
	//huỷ các thao tác copy
	CircleToStringConverter(const CircleToStringConverter&) = delete;
	void operator=(const CircleToStringConverter&) = delete;
	//tạo và lấy instace
	static shared_ptr<CircleToStringConverter> getInstanceCircleToStringConverter() {
		if (instanceCircleToStringConverter == nullptr) {
			instanceCircleToStringConverter.reset(new CircleToStringConverter());
		}
		return instanceCircleToStringConverter;
	}
	wstring convertData(shared_ptr<Shape>);
	wstring convertDataCVDT(shared_ptr<Shape>);
};