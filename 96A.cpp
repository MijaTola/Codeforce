#include <bits/stdc++.h>

using namespace std;

int main(){

	string x;
	cin >> x;
	bool sw = false;
	int c = 1;
	for (int i = 1; i < x.size(); ++i)
	{
		if(x[i] == x[i-1]) c++;
		else{
			if(c >= 7) return cout << "YES",0;
			c = 1;
		}
	}
		if(c >= 7) return cout << "YES",0;
	cout << "NO";
	return 0;
}