#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	int v[100000];
	cin >> n >> k;
	if(n == k) return cout << -1, 0;
	for (int i = 1; i < n - k; ++i)
		cout << i + 1 << " ";
	cout << 1 << " ";
	for (int i = n-k+1; i <= n; ++i)
		cout << i << " ";
	return 0;
}