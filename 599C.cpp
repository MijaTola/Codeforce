#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int v[100000];
	int m[100005];	
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	m[n] = 1e9+4;
	for (int i = n-1; i >= 0; --i)
		m[i] = min(m[i+1],v[i]);
	
	int ans = 0;
	int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		maxi = max(maxi,v[i]);
		if(maxi <= m[i+1]) ans++;
	}
	cout << ans << endl;
	return 0;
}