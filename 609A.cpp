#include <bits/stdc++.h>

using namespace std;

int main(){
	int m,n,a;
	priority_queue<int> q;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> a; q.push(a);
	}
	int ans = 0;
	while(!q.empty() && m > 0){
		ans++;
		int x = q.top(); q.pop();
		m -= x;
	}
	cout << ans;
	return 0;
}