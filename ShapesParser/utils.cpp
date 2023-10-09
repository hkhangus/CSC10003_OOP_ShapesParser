#include "utils.h"

string GetCurrentDirectory()
{
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");

    return std::string(buffer).substr(0, pos);
}

void readfileDLL( ParserFactory& factory, StringConverterStrategy& strategy, string& nameFile){
    string nameShape = nameFile.substr(0, nameFile.find("."));
    HMODULE hLib = nullptr;
    hLib = LoadLibrary(CA2W(nameFile.c_str())); // CA2W converts string/const char* to wchar
    if (hLib) { //nếu tìm thấy thư viện
        //
        listDLL.push_back(hLib);
        // Declare a function pointer to retrieve shape parser from DLL
        shared_ptr<IParser> (*getParser)(); 
        getParser = (shared_ptr<IParser>(*)()) GetProcAddress(hLib, "getParser");
        
        // Declare a function pointer to retrieve shape to string converter from DLL
        shared_ptr<IShapeToStringConverter> (*getConverter)();
        getConverter = (shared_ptr<IShapeToStringConverter>(*)()) GetProcAddress(hLib, "getToStringConverter");
        
        
        //Nếu tồn tại các chức năng của DLL bên trên thì config vào parse factory và strategy converter
        if (hLib && getParser && getConverter) {
            cout << "Loaded " << nameFile << " successfully\n";

            shared_ptr<IParser> parser = getParser();
            shared_ptr<IShapeToStringConverter> converter = getConverter();

            factory.registerWith(nameShape, parser); //đăng ký parser cho factory

            if ("Rectangle" == nameShape) { //kiểm soát trường hợp Rectangle vì class tên RRectangle để tránh trùng kiểu dữ liệu có sẵn trong lib c++
                nameShape = "RRectangle";
            }
            strategy.registerWith("class " + nameShape, converter); //đăng kí converter cho strategy
        }
        else {
            cout << "Loaded " << nameFile << " failed\n";
        }
    }
}

void freeLibs() {
    for (int i = 0;i < listDLL.size();i++) {
        wcout << FreeLibrary(listDLL[i]) << " ";
    }
}