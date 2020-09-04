#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ll n,k;
	cin >> n >> k;
	ll t,f;
	ll ans = -9999999999;
	for (ll i = 0; i < n; ++i)
	{
		cin >> f >>t;
		ll happy;
		if(t > k)  happy = f - (t-k);
		else happy = f;
		ans = max(happy,ans);
	}

	cout <<ans << endl;
	return 0;
}