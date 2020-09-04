#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	cin >> n;

	int ans = 0;
	int pos = 1;
	for (int i = 0; i < n; ++i)
	{
		ans+=2;
		cin >>x;
		ans += abs(x - pos);
		pos = x;
	}
	cout << ans;
	return 0;
}