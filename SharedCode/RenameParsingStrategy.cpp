#include "RenameParsingStrategy.h"
using namespace std;

vector<string> RenameParsingStrategy::parse(string command) {
	vector<string> names;
	names.push_back(command);
	names.push_back(command.substr(0, command.find(' ')));
	return names;
};