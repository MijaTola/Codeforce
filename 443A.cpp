#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
	string x;

	getline(cin,x);
	set<char> p;
	for (int i = 0; i < x.size(); ++i)
	{
		if(isalpha(x[i])) p.insert(x[i]);
	}

	cout << p.size() << endl;
	return 0;
}