#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){

	ll n,m,x;
	cin >> n >> m;
	ll sum = 0;
	ll pos = 1;
	for (ll i = 0; i < m; ++i)
	{
		cin >> x;
		ll dif = x - pos;
		if(dif < 0) dif += n;
		pos = x;
		sum += dif;
	}
	cout << sum;
	return 0;
}