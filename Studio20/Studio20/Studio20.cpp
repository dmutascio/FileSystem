// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include <string>
using namespace std;

int main()
{
	string s = "file.txt";
	TextFile file(s);
	PasswordProxy proxy(&file, "password");

	proxy.write({ 'h', 'i' });
	proxy.read();
	return 0;
}

