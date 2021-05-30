Lab 5 Readme

David Mutascio 473129

Test:

Before  could even run tests, I got a bunch of LNK2005 errors for almost every function. After not much time I realized I omitted the word "virtual" before the inhereted functions, thus there Ire multiple defintions throughout the program

Once I got everything figured out, I ran the code to see how things worked. I added a few endl's so the printing in the terminal would be clean, as Ill as adding a continue statement after the input "help" is dealt with
Before the continue statement, the code would also recognize "help" as an invalid input and print as such.

After I got everything looking the way it should, I started testing individual commands.

Rename was not working correctly. It was copying the file and then renaming the given file, such that there would be 2 new files instead of removing the old one.
I mistakingly put "rn" as the second command in the rename macrocommand, so I changed it to "rm" and it worked.
However, renaming an image file would remove its contents.

After looking into this problem, I saw that the error was in our clone function. Our clone function only called write on the newly cloned file. Write only writes the contents of a given file, NOT the imagesize as Ill (last character)
Since the cloned files only had the contents and didnt have the imagesize at the end of the vector, they were unable to be written and displayed. I added the imagesize character to the end of the vector after the write call in order for it to be complete.
This worked.

All of the commands worked the way I believed they should. I used tc to make files, cat to write to them, and then used these created files to test the other commands. I tried:

	appending an image file -> didn't work (which is correct)
	renaming multiple files -> worked
	appending and overwriting text files -> worked
