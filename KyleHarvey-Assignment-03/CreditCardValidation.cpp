#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;

/*
* Kyle Harvey
* CSC 340.05
* 915139815
*/

bool isvalidcc(const string& s) {

	// determines if the length is invalid
	if (s.length() < 13 || s.length() > 16) 
		return false;

	// determines if the prefix is valid or not
	if (!(s[0] == '4' || s[0] == '5' || s[0] == '6' || s.substr(0, 2) == "37")) 
		return false;

	int value;
	int digit = 0;
	int sum1 = 0, sum2 = 0, sum;

	

	for (int i = s.length() - 2; i >= 0; i -= 2) {
		digit = s[i] - '0';
		value = digit * 2;

		// determines if the value is double digit, then sums up those digits
		if (value >= 10) 
			value = 1 + (value % 10);
		sum1 += value;
	}

	for (int i = s.length() - 1; i >= 0; i -= 2) {
		digit = s[i] - '0';
		sum2 += digit;
	}

	sum = sum1 + sum2;
	

	if (sum % 10 == 0)
		return true;
	else
		return false;
}

int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};

	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2) << i << " "
			<< setw(17) << *itr
			<< ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}

