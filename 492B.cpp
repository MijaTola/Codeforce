#include <bits/stdc++.h>

using namespace std;
typedef long double	 ll;
int main(){
	ll n,l,x;
	cin >> n >> l;
	vector<ll> v;
	for (ll i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	ll dmax = -1;
	for(ll i = 1; i < v.size(); ++i){
		ll d = v[i] - v[i -1];
		dmax = max(d,dmax);
	}
	ll ans = max(dmax/2,max(v[0]-0,l-v[n-1]));
	cout.precision(9);
	cout << fixed << ans;	
	return 0;
}