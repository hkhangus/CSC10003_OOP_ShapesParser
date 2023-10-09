#include "ParserFactory.h"

void ParserFactory::registerWith(string type, shared_ptr<IParser> parser) {
	_prototypes.insert({ type,parser });
}

shared_ptr<IParser> ParserFactory::select(string type) {
	shared_ptr<IParser> parser = nullptr;

	if (_prototypes.contains(type)) {
		parser = _prototypes[type];
	}

	return parser;
}