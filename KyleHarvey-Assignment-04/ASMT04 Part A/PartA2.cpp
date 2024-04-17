#include <iostream>
#include <memory>;
#include <string>;
#include "Name.h";

using namespace std;

//Example 2: object destruction at the end of a function block Read: let the pointer do it by 
//by itself without using .reset(). Assuming we use class Name, given in-lecture. 

int main() {
	unique_ptr<Name> bugs{ make_unique<Name>("Bugs", "Bunny")
	};

	cout << "bugs, uPtr, @" << &bugs << endl; //output: bugs, uPtr, @00F3FAD0
	cout << "bugs, uPtr, memory value: " << bugs << endl; //output: bugs, uPtr, memory value @013C5B80
	cout << "bugs, uPtr, owned obj located @" << bugs.get() << endl; //output: bugs, uPtr, obj @013C5B80
	cout << "Destruction happening now..." << endl; //Last command of the function block
	
	//now, the compiler calls ~Name by itself and outputs “Name, Destructor: 013C5B80,
	//Bugs Bunny” to show you that the object has been destroyedand the SP has been nullified.

}
