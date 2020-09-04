#include <bits/stdc++.h>

using namespace std;
typedef vector<string> vs;
int main(){
	int n;
	vs rat;
	vs child;
	vs man;
	vs capitan;

	cin >> n;
	string x,y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		if(y == "child" or y == "woman") child.push_back(x);
		if(y == "rat") rat.push_back(x);
		if(y == "man") man.push_back(x);
		if(y == "captain") capitan.push_back(x);
	}

	for (int i = 0; i < rat.size(); ++i)
		cout << rat[i] << endl;
	for (int i = 0; i < child.size(); ++i)
		cout << child[i] << endl;
	for (int i = 0; i < man.size(); ++i)
		cout << man[i] << endl;
	for (int i = 0; i < capitan.size(); ++i)
		cout << capitan[i] << endl;

	
	return 0;
}