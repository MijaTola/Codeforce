#include <bits/stdc++.h>

using namespace std;
int main(){

	int n,m,k,x;
	cin >> n >> m >> k;
	
	priority_queue<int> p;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;x--; p.push(x);
	}
	if(m <= k){cout << 0; return 0;}
	int count = 0;
	while(m > k){
		m -= p.top(); p.pop();
		count++;
		if(count > n){cout << -1; return 0;}
	}

	cout << count;
	return 0;
}