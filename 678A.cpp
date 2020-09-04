#include<iostream>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll n,k;
	cin >> n >> k;
	ll ans = (n/k+1)*k;
	cout << ans << endl;
	return 0;
}

