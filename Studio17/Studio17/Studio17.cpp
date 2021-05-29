// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"

using namespace std;


int main()
{
	/*
	ImageFile i = ImageFile("hi");
	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ','X', '3' };
	i.write(v); 
	i.read();
	*/
	SimpleFileSystem sfs;
	int file = sfs.createFile("FileName.txt");



	return 0;
}

