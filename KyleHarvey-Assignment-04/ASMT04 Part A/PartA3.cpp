#include <iostream>
#include <memory>;
#include <string>;
#include "Name.h";

using namespace std;


int main() {
	//Example 3: assume it’s the same program as in Example 2.
	unique_ptr<Name> daffy{ move(bugs) }; //moved object bugs to new uPtr to help us follow along

	cout << "After moving from bugs to daffy" << endl;
	cout << "uPtr daffy owns object: " << daffy.get() << endl; //output: uPtr daffy owns object : 013C5B80

	daffy.reset(); //output: “Name, Destructor: 013C5B80. Bugs Bunny”
	cout << "uPtr daffy now owns: " << daffy.get() << endl; //output: “uPtr daffy now
	// owns: 00000000.” ... reset(), in layman’s terms, tells the SP it’s no longer neededand
	// destroys the object before the function block is over, rather than leaving that process
	// for the end of the code block.

}



int bugs;