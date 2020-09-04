#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int v[100000];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	if(n == 1){
		cout << 1; return 0;
	}
	if(n == 2){
		cout << 2; return 0;
	}
	int ans = -1;
	int l = 1;
	int r;
	for (r = 3; r <= n; ++r)
	{
		if(v[r] != v[r-1] + v[r-2]){
			ans = max(ans,r-l);
			l = r-1;
		}
	}
	r--;
	ans = max(ans,r-l+1);
	cout << ans;
	return 0;
}