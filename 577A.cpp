#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ll n,x;
	cin >> n >> x;
	ll ans = 0;
	for (ll i = 1; i <= n; ++i)
			if(x%i == 0 && x <= i*n) 
				ans++;
	cout << ans;
	return 0;
}