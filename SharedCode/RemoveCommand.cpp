#include "RemoveCommand.h"
#include <iostream>
#include <string>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* system) : afs(system) {};

int RemoveCommand::execute(string name) {
	return afs->deleteFile(name);
}

void RemoveCommand::displayInfo() {
	cout << "Remove removes a file, remove can be invoked with the command: rm <filename>" << endl;
};