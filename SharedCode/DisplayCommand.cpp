#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include <iostream>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* system) : afs(system) {};

int DisplayCommand::execute(std::string command) {
	AbstractFile* file;
	string fileName = command.substr(0, command.find(" "));
	if (command.find("-d") != string::npos) {
		file = afs->openFile(fileName);
		if (file == nullptr) {
			return static_cast<int>(errorMessage::noOpen);
		}
		vector<char> contents = file->read();
		for (size_t c = 0; c < contents.size(); c++) {
			cout << contents[c];
		}
		cout << endl;
		afs->closeFile(file);
		return static_cast<int>(errorMessage::success);
	}
	else {
		file = afs->openFile(fileName);
		if (file == nullptr) {
			return static_cast<int>(errorMessage::noOpen);
		}
		BasicDisplayVisitor display;
		file->accept(&display);
		afs->closeFile(file);
		cout << endl;
		return static_cast<int>(errorMessage::success);
	}
};

void DisplayCommand::displayInfo() {
	cout << "Display displays the contents of a file, display can be invoked with the command: ds <filename> [-d]" << endl;
};
