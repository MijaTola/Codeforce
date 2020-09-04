#include <bits/stdc++.h>

using namespace std;
int main(){
	int n,k;
	int cash[100];
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> cash[i];

	int ans = 999999;
	for (int i = 0; i < n; ++i)
	{	
		int total = 0;
		for (int j = 0; j < cash[i]; ++j)
		{
			int x; cin >> x;
			int tim = (x*5)+15;
			total += tim;
		}
		ans = min(total,ans);
	}
	cout << ans;
	return 0;
}