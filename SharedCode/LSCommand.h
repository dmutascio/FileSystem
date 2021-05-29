#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>


class LSCommand : public AbstractCommand {
public:
	AbstractFileSystem* afs;
	LSCommand(AbstractFileSystem*);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;
};