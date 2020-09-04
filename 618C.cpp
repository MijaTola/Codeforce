#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;

pair<pll, int> v[100050];
int main() {
	int n, t1, t2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t1 >> t2;
		v[i] = make_pair(pii(t1, t2), i);
	}
	sort(v + 1, v + n + 1);

	for (int i = 1; i <= n - 2; i++) {
		ll x1 = v[i + 1].first.first - v[i].first.first;
		ll y1 = v[i + 1].first.second - v[i].first.second;
		ll x2 = v[i + 2].first.first - v[i].first.first;
		ll y2 = v[i + 2].first.second - v[i].first.second;

		if (x1 * y2 != x2*y1){
			 cout << v[i].second<<" " << v[i + 1].second << " " << v[i + 2].second;
			return 0;
		}
	}

	return 0;
}
