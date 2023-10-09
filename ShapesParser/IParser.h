#pragma once
#include <iostream>
#include <sstream>
#include <regex>
#include <string>
#include <memory>

#include "Object.h"
#include "Shape.h"


using std::stringstream;
using std::regex, std::regex_match;
using std::string;
using std::shared_ptr, std::make_shared;

//INTERFACE Parser
class IParser //: public Object 
{
public:
	virtual shared_ptr<Shape> parse(stringstream data) = 0;
	string toString() { return "IParser"; }
};