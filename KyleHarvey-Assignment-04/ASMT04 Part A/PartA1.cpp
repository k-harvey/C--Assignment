#include <iostream>
#include <memory>;
#include <string>;



using namespace std;
int main() {

	int* paper = nullptr;
	paper = new int(56);
	int* rock = paper; // in directly, two pointers now reference the same object
	delete paper;

	delete paper; // now the memory is corrupted.

	cout << "Paper points to: " << paper << endl; // throws an exception when the compiler reaches that line of code. 
												// Just one example of what effects corrupted memory has on a program.
}
