#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){

	ll t,n;
	cin >> t;
	while(t--){
		cin >> n;
		ll ans = n*(n+1)/2;
		ll c = 1;
		while(c <= n){
			ans -= c*2;
			c <<=1;
		}
		cout << ans << endl;
	}
	return 0;
}