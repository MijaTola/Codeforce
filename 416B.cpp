#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,x;
	int ans[7];
	memset(ans,0,sizeof ans);
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= m; ++j){
			cin >> x;
			ans[j] = max(ans[j], ans[j-1]) + x;
		}
		cout << ans[m] << " ";
	}
	return 0;
}
