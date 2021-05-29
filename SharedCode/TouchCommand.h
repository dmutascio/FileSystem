#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand : public AbstractCommand {
public:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	virtual void displayInfo() override;
	virtual int execute(std::string) override;
};