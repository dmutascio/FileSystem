// definition of ImageFile class here

#include "ImageFile.h"
#include "AbstractFileVisitor.h"
#include <iostream>

using namespace std;

ImageFile::ImageFile(string s) : fileName_(s), imageSize_(0) {

}

unsigned int ImageFile::getSize() {
	return static_cast<unsigned int>(fileContents_.size());
}

string ImageFile::getName() {
	return (fileName_);
}

int ImageFile::write(vector<char> v) {
	int vSize = static_cast<int>(v.size());
	imageSize_ = v[static_cast<int>(vSize - 1)];
	int intSize = imageSize_ - '0';

	if ((intSize * intSize) != (vSize - 1)) {
		
		fileContents_.clear();
		imageSize_ = '0';
		return static_cast<int>(errorMessageFile::wrongSize);
	}

	for (int i = 0; i < (intSize * intSize); ++i) {

		if (v[i] != 'X' && v[i] != ' ') {
			fileContents_.clear();
			imageSize_ = '0';
			return static_cast<int>(errorMessageFile::wrongSymbol);
		}
		else {
			fileContents_.push_back(v[i]);
		}
		
	}

	return static_cast<int>(errorMessageFile::success);

}

int ImageFile::append(vector<char> v) {
	return static_cast<int>(errorMessageFile::noAppend);
}

vector<char> ImageFile::read() {
	return fileContents_;
}


void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_ImageFile(this);
};

char ImageFile::getSizeImage() {
	return imageSize_;
};

AbstractFile* ImageFile::clone(string name) {
	AbstractFile* fileClone = new ImageFile(name + ".img");
	vector<char> contents = fileContents_;
	contents.push_back(imageSize_);
	fileClone->write(contents);
	return fileClone;
};
