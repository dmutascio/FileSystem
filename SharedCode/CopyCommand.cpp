#include "CopyCommand.h"
#include <iostream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* system) : afs(system) {};

int CopyCommand::execute(std::string command) {
	AbstractFile* file;
	string fileName = command.substr(0, command.find(" "));
	string copyName = command.substr(command.find(" ") + 1);
	file = afs->openFile(fileName);
	if (file == nullptr) {
		return static_cast<int>(errorMessage::noOpen);
	}
	AbstractFile* clone = file->clone(copyName);
	afs->closeFile(file);
	int success = afs->addFile(clone->getName(), clone);

	return success;
};

void CopyCommand::displayInfo() {
	cout << "Copy makes a copy of a file, copy can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension>" << endl;
};