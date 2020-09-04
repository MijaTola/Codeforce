#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	string word;
	vector <char> p;
	cin >> word;

	for (int i = 0; i < word.size(); ++i)
		if(word[i] != '+') p.push_back(word[i]);

	sort(p.begin(),p.end());
	cout << p[0] ;
	for (int i = 1; i < p.size(); ++i)
	{
		cout << "+" << p[i];
	}
	return 0;
}