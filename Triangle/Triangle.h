// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TRIANGLE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TRIANGLE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TRIANGLE_EXPORTS
#define TRIANGLE_API __declspec(dllexport)
#else
#define TRIANGLE_API __declspec(dllimport)
#endif

#include <iostream>
#include <sstream>

#include "Shape.h"
#include "IParser.h"
#include "IShapeToStringConverter.h"

// This class is exported from the dll
class TRIANGLE_API Triangle : public Shape
{
private:
	double _a;
	double _b;
	double _c;
public:
	Triangle(double, double, double);
public:
	bool isValid();
	vector<double> getAttribute() override;
	double chuvi() override;
	double dientich() override;
};


extern "C" TRIANGLE_API shared_ptr<IParser> getParser(); //lấy instace parser, được gọi ở chương trình chính
extern "C" TRIANGLE_API shared_ptr<IShapeToStringConverter> getToStringConverter(); //lấy instance converter, được gọi ở chương trình chính