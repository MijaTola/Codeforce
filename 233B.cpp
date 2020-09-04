#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll funcS(ll t){
	ll sum = 0;
	while(log10(t)+1 > 1){
		sum += t%10;
		t/=10;
	}
	return sum+t;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll n;
	cin >> n;

	for (int i = 1; i <= 163; ++i)
	{
		long long sol = i;
		sol = (-sol+sqrt(sol*sol + 4*n))/2;
		if(sol*sol+funcS(sol)*sol == n) return cout << sol,0;
	}
	cout << -1;
	return 0;
}