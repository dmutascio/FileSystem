// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"



int main()
{
	SimpleFileSystem sfs;
	SimpleFileFactory sff;
	TouchCommand tc(&sfs, &sff);

	CommandPrompt cp;
	cp.addCommand("touch", &tc);
	cp.run();

	return 0;
}

