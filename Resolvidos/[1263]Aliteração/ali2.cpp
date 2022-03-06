#include <iostream>
#include <string>
#include <sstream>

#define MAXCHAR 50
#define MAXWORD 100
#define MAXLINE (MAXWORD * (MAXCHAR + 1))

using namespace std;

char ignoreCase(char ch){
	if(ch >= 'A' && ch <= 'Z')
		return ch - 'A' + 'a';
	return ch;
}

int main(){
	string thisWord, lastChar1, lastChar2;
	string line;

	while(!cin.eof()){
		lastChar1 = "";
		lastChar2 = "";
		getline(cin, line);
		int count = 0;

		stringstream ss;
		ss << line;
		while(ss >> thisWord){

			//cout << "Word: "  << ignoreCase(thisWord[0]) << "\n";
			//cout << "Char1: " << ignoreCase(lastChar1[0]) << "\n";
			//cout << "Char2: " << ignoreCase(lastChar2[0]) << "\n\n\n";
			

			if(ignoreCase(thisWord[0]) == ignoreCase(lastChar1[0]) 
			   && ignoreCase(lastChar1[0]) != ignoreCase(lastChar2[0])){
				count++;
			}


			lastChar2 = lastChar1;
			lastChar1 = thisWord;
		}
		if(!cin.eof())	
			cout << count << "\n";
	}

	return 0;
}
