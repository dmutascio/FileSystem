studio 19 answers here

#1 David Mutascio

#2 The test I ran to ensure it works properly is shown by the code in main() that is included below:

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

I stored the files contents into the local variable declared in main() vector<char> v. I made an edit to the file's contents by writing v[1] = 'X'. I then called write on our ImageFile again with the modified conents. The output produced by the test was as I expected.

#3 The sequence of communication between a visitor and the object it visits starts when the visitor is passed a pointer. The pointer points to the object that the pointer is defining an operation for. This allows for the visitor to have access to the object. The visitor then dispatches a function call. I used the whiteboard feature to work on an "interaction diagram" for this pattern.

#4 The concept of "delegation" is when the state of an object is used to execute the member function of a different object via a passed pointer to allow access. The visitor pattern uses delegation to add additional functionality to a family of classes without cluttering their interface by making use of double dispatch, which is a type of delegation.

#5 In a situation where I have a lot of unique visitors, the classes in our program that would need to be modified if I decide to add a new concrete file type that should be visitable would be the visitor. This is because a visitor declares a Visit function for each class in the object structure. Based on this, a negative consequence of the visitor pattern is that its defined to perform one specific action. The visitor may need access to the client its performing some work for. I don't get to choose the interface how I would like. 
