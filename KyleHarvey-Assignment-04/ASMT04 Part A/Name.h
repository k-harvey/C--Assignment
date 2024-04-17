#pragma once
// Name.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Name {
public:
	Name();
	Name(const string&, const string&);

	~Name();

	string getFirstName() const;
	string getLastName() const;
	string getName() const;
	void setName(const string&, const string&);

private:
	string firstName{ "N/A" };
	string lastName{ "N/A" };
};