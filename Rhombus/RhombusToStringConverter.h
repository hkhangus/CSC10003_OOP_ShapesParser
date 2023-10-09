#pragma once
#include "Rhombus.h"

class RHOMBUS_API RhombusToStringConverter : public IShapeToStringConverter
{
//singleton
private:
	inline static shared_ptr<RhombusToStringConverter> instanceRhombusToStringConverter = nullptr;
	RhombusToStringConverter() {};
public:
	//ngăn chặn việc tạo instance mới
	RhombusToStringConverter(const RhombusToStringConverter&) = delete;
	void operator=(const RhombusToStringConverter&) = delete;
	//tạo và lấy instace
	static shared_ptr<RhombusToStringConverter> getInstanceRhombusToStringConverter() {
		if (instanceRhombusToStringConverter == nullptr) {
			instanceRhombusToStringConverter.reset(new RhombusToStringConverter());
		}
		return instanceRhombusToStringConverter;
	}
	wstring convertData(shared_ptr<Shape>);
	wstring convertDataCVDT(shared_ptr<Shape>);
};