// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include <vector>
#include <iostream>
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;


void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
	vector<char> contents = file->read();
	for (size_t c = 0; c < contents.size(); c++) {
		cout << contents[c];
	}
	cout << endl;
};

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
	vector<char> contents = file->read();
	char imageSize = file->getSizeImage();
	int intSize = imageSize - '0';
	for (size_t c = 0; c < intSize; c++) {
		for (size_t i = 0; i < intSize; i++) {
			cout << contents[i + c * intSize];
		}
		cout << endl;
	}
};
