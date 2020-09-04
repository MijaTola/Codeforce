#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
	ll n;
	cin >> n;
	ll v[100000];
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	ll ans = 0;

	for (int i = 1; i < n; ++i)
		if(v[i] < v[i-1]) ans += v[i-1] - v[i];
	
	cout << ans;
	return 0;
}