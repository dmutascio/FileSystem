#include "PasswordProxy.h"
#include <vector>
#include <iostream>

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* file, std::string password) : file(file), password(password) {
};


PasswordProxy::~PasswordProxy() {
	delete file;
};

string PasswordProxy::passwordPrompt() {
	cout << "Enter password: " << endl;
	string userPass;
	cin >> userPass;
	return userPass;
};

vector<char> PasswordProxy::read() {
	string userPass = passwordPrompt();
	if (userPass == password) {
		return file->read();
	}
	vector<char> empty;
	return empty;
};

int PasswordProxy::write(vector<char> v) {
	string pass = passwordPrompt();
	if (pass == password) {
		return file->write(v);
	}
	else {
		return static_cast<int>(errorMessagePassword::noWrite);
	}
};

int PasswordProxy::append(vector<char> v) {
	string pass = passwordPrompt();
	if (pass == password) {
		return file->append(v);
	}
	else {
		return static_cast<int>(errorMessagePassword::noAppend);
	}
};

unsigned int PasswordProxy::getSize() {
	return file->getSize();
};

string PasswordProxy::getName() {
	return file->getName();
};

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	string pass = passwordPrompt();
	if (pass == password) {
		file->accept(visitor);
	}
};

AbstractFile* PasswordProxy::clone(string name) {
	AbstractFile* fileClone = file->clone(name);
	PasswordProxy* proxyClone = new PasswordProxy(fileClone, password);
	return proxyClone;
};