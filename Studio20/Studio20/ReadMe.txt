Studio 20 ReadMe.txt

#1 David Mutascio

#2 It is necessary to delete the pointer to the actual file in the PasswordProxy destructor because I need to remove access to the password protected file after destruction.

#3 (no question)

#4 I dynamically allocated an Abstract File and a PasswordProxy of that file. The test I ran to ensure it works properly is shown by the code in main() that is included below:

int main()
{
	string s = "file.txt";
	TextFile file(s);
	PasswordProxy proxy(&file, "password");

	proxy.write({ 'h', 'i' });
	proxy.read();
	return 0;
}

The output produced by the test was as I expected and had no errors. 
