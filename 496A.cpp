#include <bits/stdc++.h>

using namespace std;

int n;
int v[100];
int solve(int p){
	int maxi = -1;
	int o = 0;
	for (int i = 1; i < n; ++i)
	{
		if(i == p) continue;
		int sum =  v[i] - v[o];
	//	cout << sum << endl;
		maxi = max(maxi,sum);
		o = i;
	}
	//cout << maxi << endl;
	return maxi;
}
int main(){

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ans = 9999;
	for (int i = 1; i < n-1; ++i){
		int mini = solve(i);
	//	cout << mini << endl;
		ans = min(ans,mini);
	}
	
	cout << ans << endl;
	return 0;
}