#include "ListShape.h"

ListShape::ListShape(vector<shared_ptr<Shape>>& shapes, StringConverterStrategy& strategy) {
    _shapes = shapes;
    _strategy = strategy;
}

void ListShape::printShape() {
    for (int i = 0; i < _shapes.size(); i++) {
        shared_ptr<IShapeToStringConverter> converter = _strategy.set_strategy(typeid(*_shapes[i]).name());
        if (converter == nullptr) {
            continue;
        }
        wcout << i + 1 << ". " << converter->convertData(_shapes[i]) << endl;
    }
}

void ListShape::sortAreaByAsc() {
    if (_shapes.size() == 0) {
        return;
    }
    for (int i = 0; i < _shapes.size() - 1;i++) {
        int min = i;
        for (int j = i + 1; j < _shapes.size();j++) {
            if (_shapes[j]->dientich() < _shapes[min]->dientich()) {
                min = j;
            }
        }
        swap(_shapes[min], _shapes[i]);
    }
}

void ListShape::printShapeComplete() {
    for (int i = 0; i < _shapes.size(); i++) {
        wcout << "| " << i + 1 << " | ";
        shared_ptr<IShapeToStringConverter> converter = _strategy.set_strategy(typeid(*_shapes[i]).name());
        if (converter == nullptr) {
            //wcout << "dont have stratery convert\n";
            wcout << typeid(*_shapes[i]).name() << " " << _shapes[i]->chuvi() << " " << _shapes[i]->dientich() << endl;
            continue;
        }

        wstring info = converter->convertDataCVDT(_shapes[i]);
        wcout << info << endl;
    }
}