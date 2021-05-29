// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>

using namespace std;


void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
	cout << file->getName() << "     ";
	cout << "text" << "     ";
	cout << file->getSize() << endl;
};

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	cout << file->getName() << "     ";
	cout << "image" << "     ";
	cout << file->getSize() << endl;
};