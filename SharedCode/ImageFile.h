#pragma once
#include"AbstractFile.h"
// Image file class declaration here

class ImageFile : public AbstractFile {
public:
	ImageFile(std::string s);
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual int write(std::vector<char> v) override;
	virtual int append(std::vector<char> v) override;
	virtual std::vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string) override;
	char getSizeImage();

private:
	std::string fileName_;
	std::vector<char> fileContents_;
	char imageSize_;
};