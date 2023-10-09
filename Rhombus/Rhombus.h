// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the RHOMBUS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// RHOMBUS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RHOMBUS_EXPORTS
#define RHOMBUS_API __declspec(dllexport)
#else
#define RHOMBUS_API __declspec(dllimport)
#endif

#include <iostream>
#include <sstream>
#include <math.h>
#include "Shape.h"
#include "IParser.h"
#include "IShapeToStringConverter.h"

// This class is exported from the dll
class RHOMBUS_API Rhombus : public Shape
{
private:
	double _d1;
	double _d2;
public:
	Rhombus(double, double);
public:
	vector<double> getAttribute() override;
	double chuvi() override;
	double dientich() override;
};


extern "C" RHOMBUS_API shared_ptr<IParser> getParser(); //lấy ra parser instance, được gọi ở chương trình thực thi
extern "C" RHOMBUS_API shared_ptr<IShapeToStringConverter> getToStringConverter(); //lấy ra converter instance, được gọi ở chương trình thực thi