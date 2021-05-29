#pragma once
#include <vector>
#include <string>
#include "AbstractFileVisitor.h"
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

class AbstractFile {
public:
	virtual std::vector<char> read()=0;
	virtual int write(std::vector<char> v)=0;
	virtual int append(std::vector<char> v)=0;
	virtual unsigned int getSize()=0;
	virtual std::string getName()=0;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual AbstractFile* clone(std::string) = 0;

	virtual ~AbstractFile() = default;
};

enum struct errorMessageFile { success = 0, noAppend, wrongSymbol, wrongSize };
