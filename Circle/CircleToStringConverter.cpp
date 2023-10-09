#include "pch.h"
#include "framework.h"
#include "CircleToStringConverter.h"

wstring CircleToStringConverter::convertData(shared_ptr<Shape> shape) {
	wstringstream builder;
	vector<double> attribute = shape->getAttribute(); //lấy dữ liệu r

	builder << L"Hình tròn: Bán kính=" << attribute[0]; //ghép thành chuỗi hiện thị
	wstring res = builder.str(); //convert wstring
	return res;
}

wstring CircleToStringConverter::convertDataCVDT(shared_ptr<Shape> shape) {
	wstringstream builder;
	vector<double> attribute = shape->getAttribute(); //lấy dữ liệu r

	//tạo chuỗi con gồm r
	wstringstream buildCanh;
	buildCanh << L"Bán kính=" << attribute[0];
	wstring canh = buildCanh.str();

	//tạo chuỗi con là chuvi
	wstringstream buildCv;
	buildCv << "Chu vi = " << fixed << setprecision(1) << shape->chuvi(); //lấy 1 chữ số thập phân
	wstring chuvi = buildCv.str();

	//tạo chuỗi con là double
	wstringstream buildDt;
	buildDt << L"Diện tích = " << fixed << setprecision(2) << shape->dientich(); //lấy 1 chữ số thập phân
	wstring dientich = buildDt.str();

	//ghép các chuỗi con thành chuỗi hoàn chỉnh có khoảng cách cho mỗi chuỗi con
	builder << setw(space) << left << L"Hình tròn" << "| " << setw(space) << left << canh << "| " << setw(space) << left << chuvi << "| "
		<< setw(space) << left << dientich << "|";
	wstring res = builder.str();
	return res;
}

shared_ptr<IShapeToStringConverter> getToStringConverter() {
	return CircleToStringConverter::getInstanceCircleToStringConverter();
}