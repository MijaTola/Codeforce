#include <bits/stdc++.h>

using namespace std;

int main(){
	set<int> ans;
	int x;
	for (int i = 0; i < 4; ++i)
	{
		cin >> x;
		ans.insert(x);
	}

	cout << 4 - ans.size();
	return 0;
	