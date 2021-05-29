#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <string>

class CommandPrompt {
public: 
	std::map <std::string, AbstractCommand*> map;
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
	CommandPrompt();
	~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	std::string prompt();
};

enum struct errorMessagePrompt { success = 0, quit };