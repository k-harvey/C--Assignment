#include <iostream>
#include<memory>

using namespace std;

class book
{
	int* ptr;
public:
	book()
	{
		ptr = new int;
	}
	~book()
	{
	}
};
int main() {
	//declare smart pointer pointing to object of a class
	unique_ptr<book> objPtr;
	//convert unique_ptr to shared pointer
	shared_ptr <book> sharedObjPtr = move(objPtr);
}