#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll n;
	cin >> n;
	ll i;
	n--;
	for (i = 1; i <= n; ++i)
		n -= i;
	

	cout << n+1;
}	