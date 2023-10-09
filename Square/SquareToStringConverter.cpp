#include "pch.h"
#include "framework.h"
#include "SquareToStringConverter.h"

/// Square converter ///
wstring SquareToStringConverter::convertData(shared_ptr<Shape> square) { //convert chỉ gồm các thuộc tính của hình
	wstringstream builder; //biến tạo chuỗi
	vector<double> attribute = square->getAttribute(); //lấy cạnh hình vuông
	builder << L"Hình vuông: Cạnh=" << attribute[0]; //kết chuỗi
	wstring res = builder.str(); //convert vè string
	return res;
}

wstring SquareToStringConverter::convertDataCVDT(shared_ptr<Shape> square) { //convert bao gồm thuộc tính, chu vi, diện tích
	wstringstream builder; //biến để kết chuỗi
	vector<double> attribute = square->getAttribute(); //lấy ra cạnhh hình vuông
	
	//tạo string "Cạnh=..."
	wstringstream buildCanh;
	buildCanh << L"Cạnh=" << attribute[0];
	wstring canh = buildCanh.str();

	//tạo string "Chu vi=..."
	wstringstream buildCv;
	buildCv << "Chu vi = " << fixed << setprecision(1) << square->chuvi(); //lấy 1 chữ số thập phân
	wstring chuvi = buildCv.str();

	//tạo string "Diện tích=..."
	wstringstream buildDt;
	buildDt << L"Diện tích = " << fixed << setprecision(2) << square->dientich(); //lấy 2 chữ số thập phân
	wstring dientich = buildDt.str();

	//Thêm tên hình, khoảng cách giữa các thuộc tính và gộp lại các chuỗi bên trên thành chuỗi thông tin hoàn chỉnh
	builder << setw(space) << left << L"Hình vuông" << "| " << setw(space) << left << canh << "| " << setw(space) << left << chuvi << "| "
		<< setw(space) << left << dientich << "|";
	wstring res = builder.str();
	return res;
}

shared_ptr<IShapeToStringConverter> getToStringConverter() {
	//return make_shared<SquareToStringConverter>();
	return SquareToStringConverter::getInstanceSquareToStringConverter();
}