#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,l,m;
	cin >> n;

	int x = 0, y = 0;
	int ans1 = 0,ans2 = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> l; ans1 |= l;
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> m; ans2 |= m;
	}

	cout << ans2 + ans1;
	return 0;
}