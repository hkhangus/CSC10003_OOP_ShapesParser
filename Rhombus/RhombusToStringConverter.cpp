#include "pch.h"
#include "framework.h"
#include "RhombusToStringConverter.h"

wstring RhombusToStringConverter::convertData(shared_ptr<Shape> shape) {
	wstringstream builder;
	vector<double> attribute = shape->getAttribute(); //lấy số liệu 2 đường chéo hình thoi

	builder << L"Hình thoi: Đường chéo a=" << attribute[0] << L", Đường chéo b=" << attribute[1]; //ghép các chuỗi dữ liệu
	wstring res = builder.str(); //đổi sang wstring
	return res;
}

wstring RhombusToStringConverter::convertDataCVDT(shared_ptr<Shape> shape) {
	wstringstream builder;
	vector<double> attribute = shape->getAttribute(); //lấy số liệu 2 đường chéo hình thoi

	//xâu hiển thị 2 thuộc tính đường chéo
	wstringstream buildCanh;
	buildCanh << L"Chéo a=" << attribute[0] << ", " << L"Chéo b=" << attribute[1];//ghép chuỗi
	wstring canh = buildCanh.str(); //đổi sang wstring

	//xâu hiển thị chu vi
	wstringstream buildCv;
	buildCv << "Chu vi = " << fixed << setprecision(1) << shape->chuvi(); //lấy 1 chữ số thập phân
	wstring chuvi = buildCv.str(); //convert sang wstring

	//xâu hiển thị diện tích
	wstringstream buildDt;
	buildDt << L"Diện tích = " << fixed << setprecision(2) << shape->dientich(); //lấy 2 chữ số thập phân
	wstring dientich = buildDt.str(); //convert sang wstring

	//ghép lại các chuỗi con bên trên và thêm khoảng cách
	builder << setw(space) << left << L"Hình thoi" << "| " << setw(space) << left << canh << "| " << setw(space) << left << chuvi << "| "
		<< setw(space) << left << dientich << "|";
	wstring res = builder.str();
	return res;
}

shared_ptr<IShapeToStringConverter> getToStringConverter() {
	//return make_shared<RhombusToStringConverter>();
	return RhombusToStringConverter::getInstanceRhombusToStringConverter();
}