#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	int y[100001];
	int c[100001];
	int x[100001];
	int ans1,ans2;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x[i] >> y[i];
		c[x[i]]++;
	}

	for (int i = 0; i < n; ++i)
	{
		ans1 = n - 1 + c[y[i]];
		ans2 = 2*(n-1) - ans1;
		cout << ans1  << " " << ans2  << endl;
	}
	return 0;
}