#pragma once
#include "Triangle.h"

class TRIANGLE_API TriangleToStringConverter : public IShapeToStringConverter
{
//singleton
private:
	inline static shared_ptr<TriangleToStringConverter> instanceTriangleToStringConverter = nullptr;
	TriangleToStringConverter() {};
public:
	//ngăn chặn các thao tác copy
	TriangleToStringConverter(const TriangleToStringConverter&) = delete;
	void operator=(const TriangleToStringConverter&) = delete;
	//tạo và láy instance
	static shared_ptr<TriangleToStringConverter> getInstanceTriangleToStringConverter() {
		if (instanceTriangleToStringConverter == nullptr) {
			instanceTriangleToStringConverter.reset(new TriangleToStringConverter());
		}
		return instanceTriangleToStringConverter;
	}
	wstring convertData(shared_ptr<Shape>);
	wstring convertDataCVDT(shared_ptr<Shape>);
};