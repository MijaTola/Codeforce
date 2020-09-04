#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int v[1002];
	int profit[1002];
	for (int i = 1; i <= n; ++i)
		v[i] = 1e5;
	for (int i = 0; i < m; ++i)
	{
		int r,l,t,c;
		cin >> r >> l >> t >> c;
		for (int j = r; j <= l; ++j)
		{
			if(t < v[j]){
				v[j] = t;
				profit[j] = c;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if(v[i] != 1e5) ans += profit[i]; //cout << v[i] << " " << profit[i] << endl;*/
	
	cout << ans;
	return 0;
}