// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;


AbstractFile* SimpleFileFactory::createFile(string s) {
	if (s.find("txt") != string::npos) {
		TextFile* t = new TextFile(s);
		return t;
	}

	else if (s.find("img") != string::npos) {
		ImageFile* i = new ImageFile(s);
		return i;
	}
	return nullptr;
}