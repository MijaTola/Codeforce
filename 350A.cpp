#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,a,b;

	cin >> n >> m;
	
	int maxi = -1;
	int mini = 999999;
	int v=999999;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		maxi = max(maxi,a);
		v = min(v,a);
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> b;
		mini = min(mini,b);
	}

	int ans = max(2*v,maxi);
	if(ans < mini) cout << ans;
	else cout << -1; 
}