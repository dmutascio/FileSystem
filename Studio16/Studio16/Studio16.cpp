// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>

using namespace std;

int main()
{
	string s = "file";
	TextFile t(s);
	vector<char> write = { 'h','i' };

	t.write(write);
	t.read();
	return 0;
}
