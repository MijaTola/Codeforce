#include <iostream>
#include <ctype.h>
using namespace std;

int main(){

	string word,nw;

	cin >> word;
	nw = "";

	for (int i = 0; i < word.size(); ++i)
	{
		if(word[i] != 'y'&& word[i] != 'Y'&& word[i] != 'a'&& word[i] != 'e'&& word[i] != 'i'&& word[i] != 'o'&& word[i] != 'u'&& word[i] != 'A'&& word[i] != 'E'&& word[i] != 'I'&& word[i] != 'O'&& word[i] != 'U'){
			nw+=".";
			nw+= tolower(word[i]);
		}
	}
	cout << nw << endl;
	return 0;
}