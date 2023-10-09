#include "pch.h"
#include "framework.h"
#include "RectangleToStringConverter.h"

///  converter ///
wstring RectangleToStringConverter::convertData(shared_ptr<Shape> square) {
	wstringstream builder;
	vector<double> attribute = square->getAttribute(); //lấy số liệu dài rộng

	builder << L"Hình chữ nhật: Rộng=" << attribute[0] << ", Cao=" << attribute[1]; //ghép các dữ liệu lại thành 1 chuỗi
	wstring res = builder.str(); //covert wstring
	return res;
}

wstring RectangleToStringConverter::convertDataCVDT(shared_ptr<Shape> square) {
	wstringstream builder;
	vector<double> attribute = square->getAttribute(); //lấy số liệu dài rộng

	//tạo chuỗi con gồm thuộc tính dài rộng
	wstringstream buildCanh;
	buildCanh << L"Rộng=" << attribute[0] << ", " << "Cao=" << attribute[1];
	wstring canh = buildCanh.str();

	//tạo chuỗi con hiển thị chuvi
	wstringstream buildCv;
	buildCv << "Chu vi = " << fixed << setprecision(1) << square->chuvi(); //lấy 1 chữ số thập phân
	wstring chuvi = buildCv.str();

	//tạo chuỗi con hiển thị diện tích
	wstringstream buildDt;
	buildDt << L"Diện tích = " << fixed << setprecision(2) << square->dientich(); //lấy 2 chữ số thập phân
	wstring dientich = buildDt.str();

	//ghép các chuỗi con bên trên lại và thêm khoảng cách cho các chuỗi con
	builder << setw(space) << left << L"Hình chữ nhật" << "| " << setw(space) << left << canh << "| " << setw(space) << left << chuvi << "| "
		<< setw(space) << left << dientich << "|";
	wstring res = builder.str();
	return res;
}

shared_ptr<IShapeToStringConverter> getToStringConverter() {
	return RectangleToStringConverter::getInstanceRectangleToStringConverter();
}