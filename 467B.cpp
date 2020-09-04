#include <bits/stdc++.h>

using namespace std;

int main(){
	int v[1001];
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 0; i <= m; ++i)
		cin >> v[i];

	int ans = 0;
	for (int i = 0; i < m; ++i){
		int c = 0;
		for (int j = 0; j < n; ++j)
			if((v[m]^v[i])&(1<<j))c++;
		if(c <= k) ans++;
	}
	cout << ans;
	return 0;
}
