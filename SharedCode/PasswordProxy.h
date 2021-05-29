#pragma once
#include "AbstractFile.h"

class PasswordProxy: public AbstractFile{
public: 
	PasswordProxy(AbstractFile* file, std::string password);
	~PasswordProxy();
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char> v) override;
	virtual int append(std::vector<char> v) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string) override;
private:
	AbstractFile* file;
	std::string password;
protected:
	std::string passwordPrompt();
};

enum struct errorMessagePassword { noWrite = 1, noAppend };