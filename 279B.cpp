#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,t;
	int v[100005];
	cin >> n >> t;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		v[i] += v[i-1];
	}
	int ans = -1;
	int p1, p2;
	p1 = 0;
	p2 = 1;
	while(p2 <= n){
		while(v[p2] - v[p1] > t) p1++;
		ans = max(ans,p2 - p1);
		p2++; 
	}

	cout << ans;
	return 0;
}