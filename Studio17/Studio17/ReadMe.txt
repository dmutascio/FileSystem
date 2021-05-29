Answer the studio 17 questions here.

#1 David Mutascio

#2: I didn't use a helper. But if I did, it should be private as it is only used within the class.
The test I ran in main() of Studio17.cpp was:
	ImageFile i = ImageFile("hi");
	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ','X', '3' };
	i.write(v);
	i.read();

I also tested by changing the size index of '3' to '5' in the same vector of chars as above, and it didn't execute, which is correct behavior.

#3: Programming a client to use an interface is easier to change. A single class may define/implement several different interfaces. The client depends on the interface rather than the implementation. This allows for increased flexibility.

#4: In the SimpleFileSystem class, to be able to create an object of a new concrete file type, I would need to add code in the createFile() function. I noted that the SimpleFileSystem class is entirely coded to use the AbstractFile interface, with the exception of the createFile method. And, I saw that the createFile method depends on understanding how to construct objects of each concrete file type, so like a MusicFile for example.
