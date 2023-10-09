#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <memory>

#include <io.h>
#include <fcntl.h>

#include <Windows.h>
#include <atlbase.h>
#include <atlconv.h>

#include <filesystem>
#include <experimental/filesystem>

#include "ListShape.h"

#include "IParser.h"
#include "ParserFactory.h"


#include "StringConverterStrategy.h"
#include "IShapeToStringConverter.h"



using std::cout, std::endl, std::cin, std::wcout, std::wstring, std::wstringstream;
using std::string;
using std::stringstream;
using std::ifstream, std::ios;
using std::vector;
using std::regex, std::regex_match;
using std::shared_ptr, std::make_shared;

static vector<HMODULE> listDLL;

string GetCurrentDirectory(); //lấy path của file .exe đang chạy
void readfileDLL(ParserFactory&, StringConverterStrategy&,string&); //đọc thư viện dll vừa tìm được 
void freeLibs(); //giải phóng thư viện