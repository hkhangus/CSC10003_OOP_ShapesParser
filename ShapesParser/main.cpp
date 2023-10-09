// ProjectShapes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "utils.h"


int main()
{
    //vector<HMODULE> listDLL; //lưu trữ các dll để giải phóng khi kết thúc chương trình
    ParserFactory factory; //factory parse các đối tượng hình học
    StringConverterStrategy strategy; //thực hiện chuyển đổi dữ liệu hình học qua string cho việc hiển thị

    //đọc file DLL
    string path = GetCurrentDirectory(); //path dẫn tới folder chứa file exe và dll
    cout << path << endl;
    cout << "Loading dll files. . .\n";
    for (auto& entry : std::experimental::filesystem::directory_iterator(path)){ //lấy tất cả file trong folder
        string nameFile = entry.path().filename().u8string(); //lấy tên file
        //cout << nameFile;
        string fileExtension = nameFile.substr(nameFile.find(".")+1); //xử lý lấy file extension
        //cout << nameFile << "/" << fileExtension << endl;   
        if ("dll" == fileExtension) { //nếu là file dll thì đọc file và lưu trữ vào danh sách 
            //HMODULE hLib = nullptr;
            readfileDLL(factory, strategy,nameFile); //truyền vào factory và strategy để lưu trữ chức năng mới, nameFile để tìm thư viện
        }
    }    
    cout << endl;
    
    //vector shapes để lưu trữ các hình được đọc vào
    vector<shared_ptr<Shape>> shapes;
    auto mode = _setmode(_fileno(stdout), _O_U16TEXT);

    //file input
    string input = "shapes.txt";
    ifstream reader(input, ios::in);
    if (reader.good()) {
        string line;
        getline(reader, line);
        int count = stoi(line);

        int fail = 0; //đếm các hình không đọc được
        
        //read data
        wcout << L"Đang đọc tập tin shapes.txt. . .\n";
        for (int i = 0; i < count; i++) {
            getline(reader, line); //đọc 1 dòng string
            stringstream buffer(line);
            string type;
            string data;
            getline(buffer, type, ':'); //lấy ra loại hình - xuất hiện trước dấu :
            getline(buffer, data); //lấy ra dữ liệu - phần còn loại của dòng

            shared_ptr<IParser> parser = factory.select(type); //chọn hàm parse dựa trên loại hình
            if (parser != nullptr) { //kiểm tra hàm parse đã được đăng kí thì tiến hàh parse
                shared_ptr<Shape> shape = parser->parse(stringstream(data));
                if (shape != nullptr) { //kiểm tra dữ liệu hợp lệ và parse thành công truyền hình vào danh sách
                    shapes.push_back(shape);
                }
                else { //nếu không tăng biến đếm thất bại
                    fail++;
                }
            }
            else //chương trình không có hàm parse cho loại hình này nên không parse được dữ liệu
                fail++;
        }
        //kết thúc đọc data

        ListShape listShapes(shapes, strategy); //lưu trữ các hình đọc được vào danh sách
        //print readed data
        wcout << L"Tìm thấy " << shapes.size() << "/" << count << " hình\n";
        //In danh sách hình đọc được
        listShapes.printShape();

        wcout << L"Không thể đọc được: " << fail << " hình";
        wcout << endl << endl;

        //Sắp xếp danh sách dữ liệu theo diệnt ích tăng dần
        listShapes.sortAreaByAsc();

        //In danh sách hình có chu vi diện tích mỗi hình
        listShapes.printShapeComplete();
    }
    else {
        wcout << L"Không tìm thấy file shapes.txt\n";
    }

    //giải phóng thư viện dll - tuy có thể giải phóng được nhưng có 1 lỗi gây existed console chưa tìm ra và handle
    //freeLibs();
   
    system("pause");
    return 0;
}