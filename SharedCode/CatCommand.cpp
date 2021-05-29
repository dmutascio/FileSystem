#include "CatCommand.h"
#include <string>
#include <iostream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* system) : afs(system) {};

int CatCommand::execute(string command) {
	AbstractFile* file;
	string fileName = command.substr(0, command.find(" "));
	bool append = false;
	if (command.find("-a") != string::npos) {
		append = true;
		file = afs->openFile(fileName);
		if (file == nullptr) {
			return static_cast<int>(errorMessage::noOpen);
		}
		vector<char> contents = file->read();
		for (size_t s = 0; s < contents.size(); s++) {
			cout << contents[s];
		}
		cout << endl;
	}
	else {
		file = afs->openFile(fileName);
		if (file == nullptr) {
			return static_cast<int>(errorMessage::noOpen);
		}
	}

	string input;
	vector<char> allInputs;
	bool first = true;
	cout << "$     ";
	while (true) {
		getline(cin, input);
		if (input == ":wq") {
			if (append) {
				int success = file->append(allInputs);
				afs->closeFile(file);
				return success;
			}
			else {
				int success = file->write(allInputs);
				afs->closeFile(file);
				return success;
			}
		}
		else if (input == ":q") {
			afs->closeFile(file);
			return static_cast<int>(errorMessage::success);
		}
		
		else {
			if (first) {
				first = false;
			}
			else {
				allInputs.push_back('\n');
			}
			for (size_t s = 0; s<input.size(); s++) {
				allInputs.push_back(input[s]);
			}
		}
		
	}	
};


void CatCommand::displayInfo() {
	cout << "Cat concatenates a file, cat can be invoked with the command: cat <filename> [-a]" << endl;
};