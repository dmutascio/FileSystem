#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
#include <iostream>
using namespace std;


LSCommand::LSCommand(AbstractFileSystem* system) : afs(system) {};

int LSCommand::execute(string command) {
	set<string> files;
	files = afs->getFileNames();
	if (command == "") {
		int count = 0;
		for (auto i = files.begin(); i != files.end(); i++) {
			cout << *i << "	";
			++count;
			if (count%2 == 0) {
				cout << endl;
			}

		}
		cout << endl;
		return static_cast<int>(errorMessage::success);
	}

	else if (command == "-m") {
		MetadataDisplayVisitor visitor; 
		for (auto i = files.begin(); i != files.end(); i++) {
			AbstractFile* currFile = afs->openFile(*i);
			currFile->accept(&visitor);
			afs->closeFile(currFile);
		}
		return static_cast<int>(errorMessage::success);
	}
	return static_cast<int>(errorMessage::noExecute);
};

void LSCommand::displayInfo() {
	cout << "ls shows a list of current files, ls can be invoked with the command: ls [-m]" << endl;
};