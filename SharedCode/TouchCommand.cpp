#include "TouchCommand.h"
#include "AbstractFile.h"
#include "PasswordProxy.h"
#include <iostream>
using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* system, AbstractFileFactory* factory) : afs(system), aff(factory) {
}

int TouchCommand::execute(string command) {

	if (command.find("-p") != string::npos) {
		string fileName = command.substr(0, command.find(" "));
		AbstractFile* newFile = aff->createFile(fileName);
		cout << "Enter Password" << endl;
		cout << "$    ";
		string input;
		getline(cin, input);
		AbstractFile* newFilePassword = new PasswordProxy(newFile, input);

		if (afs->addFile(fileName, newFilePassword) != 0) {
			cout << "Couldn't add file" << endl;
			return static_cast<int>(errorMessage::noAdd);
		}
		return static_cast<int>(errorMessage::success);
	}

	else{
		AbstractFile* af = aff->createFile(command);
		if (af != nullptr) {
			int i = afs->addFile(command, af);
			if (i != 0) {
				delete af;
				return static_cast<int>(errorMessage::noAdd);
			}
			return static_cast<int>(errorMessage::success);
		}
		return static_cast<int>(errorMessage::noCreate);
	}
}

void TouchCommand::displayInfo() {
	cout << "Touch creates a file, touch can be invoked with the command: touch <filename> [-p]" << endl;
}