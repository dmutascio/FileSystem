#pragma once
#include"AbstractFile.h"
// TextFile declaration goes here

class TextFile:public AbstractFile {
public:
	TextFile(std::string);
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char> v) override;
	virtual int append(std::vector<char> v) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string) override;
private:
	std::vector<char> v_;
	std::string s_;
};