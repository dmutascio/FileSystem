#include "MacroCommand.h"
#include "AbstractParsingStrategy.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* system) : afs(system), parseStrategy(nullptr) {};

int MacroCommand::execute(string command) {
	vector<string> commandsVec = parseStrategy->parse(command);
	for (size_t s = 0; s < commandsVec.size(); s++) {
		AbstractCommand* currCommand = commands[s];
		int success = currCommand->execute(commandsVec[s]);
		if (success != 0) {
			return static_cast<int>(errorMessage::noExecute);
		}
	}
	return static_cast<int>(errorMessage::success);
};

void MacroCommand::displayInfo() {

};

void MacroCommand::addCommand(AbstractCommand* command) {
	commands.push_back(command);
};

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
	parseStrategy = strategy;
};