#ifdef SQUARE_EXPORTS
#define SQUARE_API __declspec(dllexport)
#else
#define SQUARE_API __declspec(dllimport)
#endif


#include <iostream>
#include <sstream>

#include "Shape.h"
#include "IParser.h"
#include "IShapeToStringConverter.h"

class SQUARE_API Square : public Shape {
private:
	double _a;
public:
	Square(double);
public:
	vector<double> getAttribute() override;  
	double chuvi() override; 
	double dientich() override;
};

extern "C" SQUARE_API shared_ptr<IParser> getParser(); //lấy instance parser, được gọi trong hàm main
extern "C" SQUARE_API shared_ptr<IShapeToStringConverter> getToStringConverter(); //lấy instance converter, được gọi trong hàm main