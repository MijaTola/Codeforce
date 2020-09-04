#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int v[123456];
	int n,m,a;
	cin >> n >> m;
	memset(v,0,sizeof v);
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		v[a]++;
	}
	int ans = 0;
	for(int i = 1;i <= m; ++i)
		for(int j = i+1; j <= m; ++j)
			ans += v[i]*v[j];

	cout << ans;


	return 0;
}