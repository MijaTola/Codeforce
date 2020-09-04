#include <bits/stdc++.h>

using namespace std;

int main(){
	string word;

	cin >> word;
	string nw = "";
	vector<string> numbers;
	vector <string> letters;
	char dash = '\0'+45;
	char quotes = '\0'+34;
	word += ';';
 	for (int i = 0; i <= word.size(); ++i)
	{
		if(word[i] == ',' || word[i] == ';'){
			bool sw = false;
			bool o = false;
			for (int j = 0; j < nw.size(); ++j)
			{
				if(!isdigit(nw[j])){
					sw = true; break;
				}
				if(j == 0 && nw[j] == '0') o = true;
				else if(o){sw = true;break;}
			}
			if(nw == "") sw = true;
			if(sw) letters.push_back(nw);
			else numbers.push_back(nw);
			nw = "";
		}else nw +=word[i];
	}

	if(numbers.size() == 0) cout << dash << endl;
	else{
		cout << quotes << numbers[0];
		for (int i = 1; i < numbers.size(); ++i)
			cout << "," << numbers[i];
		cout << quotes << endl;
	} 
	if(letters.size() == 0) cout << dash << endl;
	else{
		cout << quotes << letters[0];
		for (int i = 1; i < letters.size(); ++i)
			cout << "," << letters[i];
		cout << quotes << endl;
	} 
	return 0;
}
 