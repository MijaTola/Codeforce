#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,x,y;
	int v[100000];
	int v1[100000];
	cin >> n;
	memset(v,0,sizeof v);
	for (int i = 0; i < n; ++i){
		cin >> x >> y;
		v[x+y]++;
		v1[x-y+1000]++;
	}
	int ans = 0;
	for (int i = 0; i < 2000; ++i){
		ans += (v[i]*(v[i]-1))/2;
		ans += (v1[i]*(v1[i]-1))/2;
	}

	cout << ans;	
	return 0;
}