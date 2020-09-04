#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ll a,b,x,y;
	cin >> a >> b >> x >> y;
	ll ans = max(abs(a-x),abs(b - y));
	cout << ans;
	return 0;
}