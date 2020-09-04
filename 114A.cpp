#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	ll k,p;
	cin >> k >> p;
	ll ans = 0;
	while(p > k && p % k == 0){
		ans++;
		p /= k;
	}
	if(p == k){
		cout << "YES" << endl << ans;
	}
	else cout << "NO";
	return 0;
}