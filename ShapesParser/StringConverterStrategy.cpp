#include "StringConverterStrategy.h"

void StringConverterStrategy::registerWith(string type, shared_ptr<IShapeToStringConverter> converter) {
	_prototypes.insert({ type,converter });
}

shared_ptr<IShapeToStringConverter> StringConverterStrategy::set_strategy(string type) {
	shared_ptr<IShapeToStringConverter> converter = nullptr;

	if (_prototypes.contains(type)) {
		converter = _prototypes[type];
	}

	return converter;
}