#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll l,r,k;
	cin >> l >>r >> k;
	ll n = 1;
	ll dif;
	bool sw = false;
	while(n <= r){
		if(n >=l){
			cout << n << " " ;
			sw = true;
		}
		dif = n;
		n*= k;
		if(n / k != dif) break;
	}
	if(!sw) cout << -1;
	return 0;
}