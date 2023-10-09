// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the RECTANGLE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// RECTANGLE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RECTANGLE_EXPORTS
#define RECTANGLE_API __declspec(dllexport)
#else
#define RECTANGLE_API __declspec(dllimport)
#endif

#include <iostream>
#include <sstream>

#include "Shape.h"
#include "IParser.h"
#include "IShapeToStringConverter.h"

// This class is exported from the dll
class RECTANGLE_API RRectangle : public Shape //để tên là RRectangle vì tránh trung với Rectangle trong file wingdi.h
{
private:
	double _w;
	double _h;
public:
	RRectangle(double, double);
	vector<double> getAttribute() override;
	double chuvi() override;
	double dientich() override;
};

extern "C" RECTANGLE_API shared_ptr<IParser> getParser(); //lấy instance parser, được gọi ở chương trình thực thi
extern "C" RECTANGLE_API shared_ptr<IShapeToStringConverter> getToStringConverter(); //lấy instance converter, được gọi ở chương trình thực thi