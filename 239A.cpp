#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll y,k,n;
	cin >> y >> k >> n;
	bool sw = false;
	for (ll i = k; i <= n; i+=k)
	{
		if(i > y){
			cout << i - y << " ";
			sw = true;
		}
	}
	if(!sw) cout << -1;
	return 0;
}