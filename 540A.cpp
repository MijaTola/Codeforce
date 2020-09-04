#include <bits/stdc++.h>

using namespace std;

int main(){
	char a,b;
	vector<int> da;
	vector<int> db;
	int n;
	cin >> n;
	//cin >> a >> b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		da.push_back(a-48);
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		db.push_back(a-48);
	}
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		if(abs(da[i] - db[i]) <= 5) c += abs(da[i] - db[i]);
		else c+= 10 - abs(da[i] - db[i]);
	}
	cout << c << endl;
	return 0;
}