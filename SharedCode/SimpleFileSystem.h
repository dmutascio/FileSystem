#pragma once
// declaration of SimpleFileSystem class goes here

#include "AbstractFileSystem.h"
#include <map>
#include <set>
#include <string>


class SimpleFileSystem : public AbstractFileSystem {
public:
	std::map <std::string, AbstractFile*> allFiles;
	std::set <AbstractFile*> openFiles;

	int addFile(std::string, AbstractFile*);
	int deleteFile(std::string);
	AbstractFile* openFile(std::string);
	int closeFile(AbstractFile*);
	virtual std::set<std::string> getFileNames() override;
};

enum struct errorMessageSystem { success = 0, notFile, notOpen };