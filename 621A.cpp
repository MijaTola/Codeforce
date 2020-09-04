#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){

	ll n,x;
	vector<ll> odd;
	vector<ll> even;
	cin >> n;

	ll ans = 0;
	for (int i = 0; i < n; ++i){
		cin >> x;
		if(x&1) odd.push_back(x);
		else ans += x;
	}	
	sort(odd.begin(),odd.end());
	int i = 0;
	if(odd.size() % 2 !=0) i = 1;
	for (int j = i; j < odd.size(); ++j)
		ans += odd[j];
	cout << ans;
	return 0;
	
}