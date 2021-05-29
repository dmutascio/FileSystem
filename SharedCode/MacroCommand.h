#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <vector>

class AbstractParsingStrategy;

class MacroCommand : public AbstractCommand {
public:
	AbstractFileSystem* afs;
	MacroCommand(AbstractFileSystem*);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
private: 
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* parseStrategy;
};