Studio 21 ReadMe.txt

#1 David Mutascio

#2 It is important to declare a virtual destructor in the base class because it is important that the appropriate destructor can be used on the derived class.

#3 "Dependency injection" allows flexibility at run-time, which makes the command prompt flexible and reusable. The command prompt can be easily configured to use these instead of the simple file system and its associated factory object because the command prompt maintains these objects and the user interface CommandPrompt issues command objects, which allows the user to interact with the file system. The user's input is used if a suitable command.

#4 I dynamically allocated a SimpleFileSystem, a SimpleFileFactory, and a TouchCommand object. The test I ran to ensure it works properly is shown by the code in main() that is included below:

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

I called run() and tested quitting, asking for help, asking for help on the touch command, and executing the touch command. The output produced by the test was as I expected and had no errors. 
