Answer studio 16 questions here

#1 David Mutascio

#2 To declare an interface, create a class. Then create a set of all functions/operators that the client should be able to request of an object.

#3 (a) This is an instance of interface inheritance

#3 (b) These member variables should be private

#4 I created a TextFile called t and wrote and read from it. I wrote a variety of things to the file, including empty strings. The file performed as expected.

#5 Unlike in question #4 where I only used the single concrete file type TextFile, I interacted with an arbitrary file type. This is accomplished by creating a pointer to an Abstract File class. Below is our main function:

int main()
{
	AbstractFile* af1 = new TextFile("tfile.img");

	vector<char> write = { "h","i" };
	af1.write(write);
	af1.read();
	return 0;
}
