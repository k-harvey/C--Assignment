#include <iostream>
#include <memory>
using namespace std;
int main()
{
	//create shared pointer
	shared_ptr<int> sharedPtr(new int);
	//create weak pointer
	weak_ptr<int> weak = sharedPtr;
	if (weak.expired())
	{
		cout << "weak pointer is expired" << endl;
	}
	cout << "Use count weak: " << weak.use_count() << endl;
	sharedPtr.reset();
	if (weak.expired())
	{
		cout << "weak pointer expired" << endl;
	}
	cout << "Use count weak: " << weak.use_count() << endl;
}