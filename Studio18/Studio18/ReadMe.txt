studio 18 answers here

#1
3. David Mutascio

#2 Using inheritance and the factory method pattern, since I use templated types, adding a new file system will require minimal change to the AbstractFileSystem. The factory method pattern is a member function. The file system won't actually be responsible for creating files just managing access to files. The factory will have that responsibility of creating, making it more flexible.

#3 The advantage of the abstract factory pattern is that it is a separate object that takes the responsibility of creating objects of other types, where the interface of the abstract factory includes methods to create objects created by the client. You would want to create a new concrete file factory class to define that AbstractFileFactory interface to handle the creation of varying concrete file types, where a concrete file factory may have restrictions. If a new file type is introduced that should be created by existing factories, you should modify the code so that the type creates a related type polymorphically. Given two files system implementations that manage the same types of files, the same factory can be used to create files for both because each type knows which related type it should create. Given two files system implementations that manage different types of files, the same concrete factory implementation can't be used to create files for both because a consequence of the factory method pattern is that the type that's created matches the type(s) it's used with.

#4 The test I ran to ensure it works properly is shown by the code in main() that is included below:

	SimpleFileSystem sfs;
	AbstractFileSystem* system = &sfs;

	SimpleFileFactory sff;
	AbstractFile* file = sff.createFile("FileName.txt");
	AbstractFileFactory* factory = &sff;

	system->addFile("FileName.txt", file);
	file->read();

The output produced by the test was as I expected and had no errors. 

#5 At this point, SimpleFileSystem depends on the AbstractFile interface only.
