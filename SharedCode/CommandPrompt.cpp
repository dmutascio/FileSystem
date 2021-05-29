#include "CommandPrompt.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

CommandPrompt::CommandPrompt() : afs(nullptr), aff(nullptr) {};

void CommandPrompt::setFileSystem(AbstractFileSystem* system) {
	afs = system;
};

void CommandPrompt::setFileFactory(AbstractFileFactory* factory) {
	aff = factory;
};

int CommandPrompt::addCommand(string str, AbstractCommand* command) {
	map.insert({ str, command });
	return static_cast<int>(errorMessagePrompt::success);
};

void CommandPrompt::listCommands() {
	for (auto i = map.begin(); i != map.end(); i++) {
		cout << i->first << endl;
	}
};

string CommandPrompt::prompt() {
	cout << "Enter a command, q to quit, help for a list of commands, or" << endl;
	cout << "help followed by a command name for more information about" << endl;
	cout << "that command." << endl;
	cout << "$    ";
	string input;
	getline(cin, input);
	return input;
};

int CommandPrompt::run() {
	while (1) {
		string s = prompt();
		if (s == "q") {
			return static_cast<int>(errorMessagePrompt::quit);
		}
		else if (s == "help") {
			listCommands();
			continue;
		}
		else if (s.find(' ') == string::npos) {
			int count = 0;
			for (auto i = map.begin(); i != map.end(); i++) {
				if (i->first == s) {
					count++;
					i->second->execute("");
				}
			}
			if (count == 0) {
				cout << "Command entered does not exist." << endl;
			}
		}
		else {
			string word_1;			
			istringstream iss(s);
			iss >> word_1;

			if (word_1 == "help") {
				string word_2;
				iss >> word_2;

				int count = 0;
				for (auto i = map.begin(); i != map.end(); i++) {
					if (i->first == word_2) {
						i->second->displayInfo();
					}
				}
				if (count == 0) {
					cout << "Command entered does not exist." << endl;
				}

			}
			else {

				int count = 0;
				
				for (auto i = map.begin(); i != map.end(); i++) {
					if (i->first == word_1) {
						count++;
						i->second->execute(s.substr(s.find(' ') + 1));
					}
				}
				if (count == 0) {
					cout << "Command entered does not exist." << endl;
				}
			}
		}
	}
};