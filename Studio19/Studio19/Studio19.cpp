// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include <iostream>

using namespace std;


int main()
{
	ImageFile i = ImageFile("hi");
	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ','X', '3' };
	i.write(v);
	i.read();
	v[1] = 'X';
	v[3] = 'X';
	i.write(v);
	i.read();

	return 0;
}
