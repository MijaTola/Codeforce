#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll n,a,b;
	ll da = 0, db = 0;
	cin >> n;
	for (ll i = 0; i < n; ++i)
	{
		cin >> a >> b;
		if(abs(da + a - db) <= 500) {da += a; cout << "A";}
		else if(abs(db + b - da <= 500)){ db += b; cout << "G";}
	}
	return 0;
}