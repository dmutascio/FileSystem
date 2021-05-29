// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"

using namespace std;

int main()
{
	SimpleFileSystem sfs;
	AbstractFileSystem* system = &sfs;

	SimpleFileFactory sff;
	AbstractFile* file = sff.createFile("FileName.txt");
	AbstractFileFactory* factory = &sff;

	system->addFile("FileName.txt", file);
	file->read();



	return 0;
}
