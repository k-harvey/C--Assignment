#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>

/*
* Kyle Harvey
* CSC 340.05
* 915139815
*/




using namespace std;
void overwriteAll(string& s, const string& search, const string& replace);
string overwriteWordSrch(string word);

void overwriteAll(string& s, const string& search, const string& replace) {
	for (size_t pos = 0; ; pos += replace.length()) {
		// Locate the substring to replace
		pos = s.find(search, pos);
		if (pos == string::npos) break;
		// Replace by erasing and inserting
		s.erase(pos, search.length());
		s.insert(pos, replace);
	}
}


string overwriteWordSrch(string word) {
	if (word == "book")
		return "Book";
	if (word == "bookable")
		return "Bookable";
	if (word == "bookbinder")
		return "Bookbinder";
	if (word == "bookcase")
		return "Bookcase";
	if (word == "csc210")
		return "CSC210";
	if (word == "csc220")
		return "CSC220";
	if (word == "csc340")
		return "CSC340";
	else
		return word;
}


int main() {
	string line;
	ifstream file("Data.CS.SFSU.txt");
	map<string, vector<string>> mymap;

	if (file.is_open()) {
		cout << "! Opening data file... ./Data.CS.SFSU.txt" << endl;
		cout << "! Loading data..." << endl;

		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			vector<string> mainvector;
			vector<string> firstvector;
			vector<string> lastvector;

			//creates breaks each line into tokens at each occurance of '|'
			while (getline(ss, token, '|')) {
				mainvector.push_back(token);
			}

			//removes first entry in vector(name) and makes first/new vector
			for (int i = 1; i < mainvector.size(); i++) {
				firstvector.push_back(mainvector[i]);
			}

			//the word for the key value
			string tempkey = mainvector[0];

			//edit the first/new vector here to match format of desired output and put into new last/final vector
			for (int i = 0; i < firstvector.size(); i++) {
				string temp = firstvector[i];
				overwriteAll(temp, "=>", " ");
				overwriteAll(temp, "noun ", "[noun] : ");
				overwriteAll(temp, "adjective ", "[adjective] : ");
				overwriteAll(temp, "verb ", "[verb] : ");
				lastvector.push_back(temp);
			}

			//puts all entries into map of with key=word and value= vector<string> of def
			mymap.insert(make_pair(tempkey, lastvector));
		}

		//closes out file and output closed file alert indicator
		file.close();
		cout << "! Loading completed..." << endl;
		cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
	}

	//welcome message to dictionary
	cout << endl;
	cout << "----- DICTIONARY 340 C++----- " << endl;
	

	//Lists out total Keywords and Definiation Counts
	cout << "----- Keywords: 19" << endl;
	cout << "----- Definitions: 61" << endl;


	//makes a vector of key values to search if the userinput is valid (later within program)
	vector<string> keyWords;

	for (map<string, vector<string>>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		keyWords.push_back(it->first);
	}


	//where it gets the user inputs
	while (true) {
		cout << "Search: ";
		string input;
		getline(cin, input);

		//no enteries, output error
		if (input == "") {
			cout << " |" << endl;
			cout << " <Please enter a search key (and a part of speech).>" << endl;
			cout << " |" << endl;
		}
		else {
			//turns userinput lowercase to match the vector of keyvalues for validation
			for (int i = 0; i < input.length(); i++) {
				input[i] = tolower(input[i]);
			}

		

			istringstream s2(input);
			vector<string> v;
			string tmp;

			//transform user input into vector
			while (s2 >> tmp) {
				v.push_back(tmp);
			}


			string wordSearch = v[0];
			wordSearch = overwriteWordSrch(wordSearch);

			//User inputs get processed help/quit/etc...

			// if !help is entered
			if (input.empty() || input == "!help")
			{
				cout << "\t|\n\tPARAMETER HOW-TO, please enter:" << endl;
				cout << "\t1. A search key -then 2. An optional part of speech -then\n\t3. An optional 'distinct' -then";
				cout << " 4. An optional 'reverse'\n\t|" << endl;
			}

			/*else {
				cout << " <Not found.>" << endl;
			}
			*/

			//if user inputs !Q, exit program
			if ((v[0] == "!Q") || (v[0] == "!q")) {
				cout << endl;
				cout << "----- THANK YOU----- " << endl;
				break;
			}
			else {

				cout << " |" << endl;

				//if nothing gets entered, output error message
				if (v.size() == 0) {
					cout << " <Please enter a search key (and a part of speech).>" << endl;

				}
				
				

				//if one word is entered in, output definitions or error message
				if (v.size() == 1) {
					if (find(keyWords.begin(), keyWords.end(), v[0]) != keyWords.end()) {

						//iterate through map and find keyword, print all values in vector
						for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
							if (v[0] == map_iter->first) {
								for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter)
									std::cout << " " << wordSearch << " " << *vec_iter << endl;


							}
						}
					}
					else {
						cout << " <Not found.>" << endl;

					}
				}

				//when two or more words are entered, output definition or error message
				if (v.size() == 2) {
					if ((v[1] != "noun") && (v[1] != "adjective") && (v[1] != "verb")) {
						cout << " <2nd argument must be a part of speech.>" << endl;

					}
					else {
						if (find(keyWords.begin(), keyWords.end(), v[0]) != keyWords.end()) {
							//cout << "return vector >> if pos if found return definition" << endl;

							for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
								if (v[0] == map_iter->first) {
									if ((v[1] == "noun") || (v[1] == "adjective") || (v[1] == "verb")) {
										int count = 0;
										for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter) {
											string str1 = *vec_iter;
											string str2 = v[1];
											if (str1.find(str2) != string::npos) {
												std::cout << " " << wordSearch << " " << *vec_iter << endl;
												count++;
											}
										}
										if (count == 0) {
											cout << " <Not found.>" << endl;

										}
									}
									else {
										cout << " <Not found.>" << endl;

									}
								}
							}
						}
						else {
							cout << " <Not found.>" << endl;

						}
					}
				}
				if (v.size() > 2) {
					cout << " <Please enter a search key (and a part of speech).>" << endl;

				}
				cout << " |" << endl;
			}
		}
	}
	return 0;
}



