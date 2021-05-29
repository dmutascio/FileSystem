// definitions of metadata visitor here
#include "MetadataDisplayVisitor2.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>

using namespace std;


void MetadataDisplayVisitor2::visit_TextFile(TextFile* file) {
	cout << file->getName() << "     ";
	cout << "text" << "     ";
	cout << file->getSize() << endl;
};

void MetadataDisplayVisitor2::visit_ImageFile(ImageFile* file) {
	cout << file->getName() << "     ";
	cout << "image" << "     ";
	cout << file->getSize() << endl;
};