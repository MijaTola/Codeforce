#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	priority_queue<int> candidates;
	cin >> n;
	bool sw = false;
	int limak;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		if(!sw){ limak = x;  sw = true; continue;}
		candidates.push(x);
	}
	int ans = 0;
	while(limak<= candidates.top()){
		int p = candidates.top();
		candidates.pop();
		p--;
		candidates.push(p);
		limak++;
		ans++;
	}
	cout << ans;
}