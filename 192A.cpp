#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 

int main(){
	ll n;
	cin >> n;
	set<ll> s;

	for (ll i = 1; i * (i + 1) >> 1 <= n; ++i)
		s.insert((i*(i+1))>>1);

	for(set<ll>::iterator it = s.begin();it!=s.end(); it++)
		if(s.count(n-*it)){cout << "YES"; return 0;}

	cout << "NO";
	return 0;
}