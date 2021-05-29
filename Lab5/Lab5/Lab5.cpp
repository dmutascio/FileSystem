// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\RenameParsingStrategy.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\CatCommand.h"
#include "..\..\\SharedCode\DisplayCommand.h"
#include "..\..\\SharedCode\CopyCommand.h"
#include "..\..\\SharedCode\MacroCommand.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"


using namespace std;

int main()
{
	SimpleFileSystem sfs;
	SimpleFileFactory sff;
	CommandPrompt command;
	RenameParsingStrategy strategy;
	command.setFileSystem(&sfs);
	command.setFileFactory(&sff);

	LSCommand ls(&sfs);
	command.addCommand("ls", &ls);

	RemoveCommand rm(&sfs);
	command.addCommand("rm", &rm);

	TouchCommand tc(&sfs, &sff);
	command.addCommand("touch", &tc);

	CatCommand cat(&sfs);
	command.addCommand("cat", &cat);

	DisplayCommand ds(&sfs);
	command.addCommand("ds", &ds);

	CopyCommand cp(&sfs);
	command.addCommand("cp", &cp);

	MacroCommand rn(&sfs);
	rn.setParseStrategy(&strategy);
	rn.addCommand(&cp);
	rn.addCommand(&rm);
	command.addCommand("rn", &rn);

	return command.run();
}


