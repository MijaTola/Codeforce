#include <bits/stdc++.h>

using namespace std;
int dx[101]; int dy[101];
int main(){
	memset(dx,0,sizeof dx);
	memset(dy,0,sizeof dy);
	int n;

	cin >> n;

	char x;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j){
			cin >> x;
			if(x == 'C'){
				dx[i]++; dy[j]++;
			}
		}
	}
	//n*(n-1)/2
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if(dx[i] >= 2)	ans += dx[i]*(dx[i]-1)/2;
		if(dy[i] >= 2)	ans += dy[i]*(dy[i]-1)/2;
	}
	cout << ans;
	return 0;
}