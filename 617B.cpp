#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ll n;
	ll dn[100];
	ll d = 0;
	cin >> n;
	for (ll i = 0; i < n; ++i)
	{
		cin >> dn[i];
		if(dn[i] == 1) d++;
	}
	if(d == n or d == 1){ cout << 1; return 0;}
	if(d == 0) { cout << 0; return 0;}
	ll ans = 1;
	ll c = 0;
	bool sw = false;
	for (ll i = 0; i < n; ++i)
	{
		if(dn[i] == 1){
			if(!sw){ sw = true; continue;}
			if(sw){
				ans *= c + 1;
				c = 0;
			}
			continue;
		}
		if(sw) c++;
	}
	cout << ans;
	return 0;
}