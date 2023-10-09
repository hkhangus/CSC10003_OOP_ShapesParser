#include "pch.h"
#include "framework.h"
#include "TriangleToStringConverter.h"

///  converter ///
wstring TriangleToStringConverter::convertData(shared_ptr<Shape> shape) {
	wstringstream builder;
	vector<double> attribute = shape->getAttribute(); //lấy số liệu 3 cạnh
	//ghép các số liệu vào 1 chuỗi
	builder << L"Hình tam giác: Cạnh a=" << attribute[0] << L", Cạnh b=" << attribute[1] << L", Cạnh c=" << attribute[2];
	wstring res = builder.str(); //convert wstring
	return res;
}

wstring TriangleToStringConverter::convertDataCVDT(shared_ptr<Shape> shape) {
	wstringstream builder;
	vector<double> attribute = shape->getAttribute(); //lấy các số liệu 3 cạnh

	//cho số liệu vào 1 chuỗi
	wstringstream buildCanh;
	buildCanh << L"Cạnh a=" << attribute[0] << L", Cạnh b=" << attribute[1] << L", Cạnh c=" << attribute[2];
	wstring canh = buildCanh.str(); 

	//chu vi 1 chuỗi
	wstringstream buildCv;
	buildCv << "Chu vi = " << fixed << setprecision(1) << shape->chuvi(); //lấy 1 chữ số
	wstring chuvi = buildCv.str();

	//diện tích 1 chuỗi
	wstringstream buildDt;
	buildDt << L"Diện tích = " << fixed << setprecision(2) << shape->dientich(); //lấy 2 chữ số
	wstring dientich = buildDt.str();

	//ghép các chuỗi trên lại và thêm khoảng cách cho mỗi chuỗi con
	builder << setw(20) << left << L"Hình tam giác" << "| " << setw(space) << left << canh << "| " << setw(space) << left << chuvi << "| "
		<< setw(space) << left << dientich << "|";
	wstring res = builder.str();
	return res;
}

shared_ptr<IShapeToStringConverter> getToStringConverter() {
	return TriangleToStringConverter::getInstanceTriangleToStringConverter();
}