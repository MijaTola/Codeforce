#include <iostream>

using namespace std;

int main(){
	string word;
	int t;
	cin >>  t;
	while(t--){
		cin >> word;
	
		if(word.size() <= 10)
			{cout << word << endl; continue;}
	
		int n = word.size() -2;
		cout << word[0] << n << word[word.size()-1] << endl;}
	return 0;
}