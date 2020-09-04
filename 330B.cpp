#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,a,b;
	bool graph[1005][600];
	bool dn[1005];
	memset(dn, false, sizeof dn);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		dn[a] = true; dn[b] = true;
	}
	int s;
	for (int i = 1; i <= n; ++i)
	{
		if(!dn[i]){s = i; break;}
	}
	cout << n - 1 << endl;
	for (int i = 1; i <= n; ++i)
	{
		if(s == i) continue;
		cout << s << " " << i << endl;
	}

	
	return 0;
}