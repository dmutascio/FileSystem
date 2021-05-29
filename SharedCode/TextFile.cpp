//  Define the TextFile class here
#include "TextFile.h"
#include <iostream>

using namespace std;

TextFile::TextFile(string s): s_(s) {

}

unsigned int TextFile::getSize() {
	return static_cast<unsigned int>(v_.size());
}

std::string TextFile::getName() {
	return s_;
}

int TextFile::write(std::vector<char> v) {
	v_ = v;
	return static_cast<int>(errorMessageFile::success);
}

int TextFile::append(vector<char> v) {
	for (size_t s = 0; s < size(v); s++) {
		v_.push_back(v[s]);
	}
	return static_cast<int>(errorMessageFile::success);
}

vector<char> TextFile::read() {
	return v_;
}

void TextFile::accept(AbstractFileVisitor* afv) {
	afv->visit_TextFile(this);
};

AbstractFile* TextFile::clone(string name) {
	AbstractFile* fileClone = new TextFile(name + ".txt");
	fileClone->write(v_);
	return fileClone;
};