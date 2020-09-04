#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	map<int ,ll> dx;
	map<int, ll> dy;
	map<pair<int,int>,ll> dxy;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ll x,y;
		cin >> x >> y;
		ans += dx[x];
		ans += dy[y];
		ans -= dxy[make_pair(x,y)];
		dx[x]++;
		dy[y]++;
		dxy[make_pair(x,y)]++;
	}

	cout << ans;
	return 0;
}