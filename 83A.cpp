#include <iostream>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
map<ll,int> m;
set<ll> s;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	ll x; cin >> x;
	ll last = x;
	ll c = 1;
	unsigned long long ans = 0;
	for (int i = 1; i < n; ++i){
		cin >> x;
		if(last == x) c++;
		else {
			ans += (c*(c-1)/2);
			last = x;
			c = 1;
		}
	}
	if(c > 1) ans += (c*(c-1)/2);
	cout << ans+n << "\n";
	return 0;
}
