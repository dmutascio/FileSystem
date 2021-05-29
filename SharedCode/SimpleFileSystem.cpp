// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <fstream>  
#include <iostream>

using namespace std;


int SimpleFileSystem::addFile(string s, AbstractFile* f) {
	if (allFiles.find(s) != allFiles.end()) {
		return static_cast<int>(errorMessageSystem::notFile);
	}
	if (f == nullptr) {
		return static_cast<int>(errorMessageSystem::notFile);
	}
	pair<string, AbstractFile*> p;
	p = make_pair(s, f);
	allFiles.insert(p);
	return static_cast<int>(errorMessageSystem::success);
}

AbstractFile* SimpleFileSystem::openFile(string s) {
	ifstream ifs(s);
	if (allFiles.find(s) == allFiles.end()) {
		return nullptr;
	}

	if (openFiles.find(allFiles[s]) == openFiles.end()) {
		openFiles.insert(allFiles[s]);
		return allFiles[s];
	} 
	
	return nullptr;
}


int SimpleFileSystem::closeFile(AbstractFile* f) {
	if (openFiles.find(f) == openFiles.end()) {
		return static_cast<int>(errorMessageSystem::notOpen);
	}
	else {
		openFiles.erase(f);
		return static_cast<int>(errorMessageSystem::success);
	}
}



int SimpleFileSystem::deleteFile(string s) {
	if (allFiles.find(s) == allFiles.end()) {
		return static_cast<int>(errorMessageSystem::notFile);
	}
	else {
		auto it = allFiles.find(s);
		if (openFiles.find(it->second) != openFiles.end()) {
			return static_cast<int>(errorMessageSystem::notOpen);
		}
		else {
			allFiles.erase(it);
			return static_cast<int>(errorMessageSystem::success);
		}
	}
}


set<string>SimpleFileSystem::getFileNames() {
	set<string> files;
	for (auto i = allFiles.begin(); i != allFiles.end(); i++) {
		files.insert(i->first);
	}
	return files;
};