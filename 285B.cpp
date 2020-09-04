#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,s,t;
	int v [100000];
	bool ver[100000];
	memset(ver,false,sizeof ver);
	cin >> n >> s >> t;
	for (int i = 1; i <= n; ++i) cin >> v[i];
	int ans = 0;
	while(s != t){
		if(ver[s]){
			cout << -1; return 0;
		}
		ans++;
		ver[s] = true;
		s = v[s];
	}
	cout << ans;
	return 0;
}