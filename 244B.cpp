#include <bits/stdc++.h>

using namespace std;

long long n;
long long ans;

long long dig(long long x){
	int c = 0;
	set<long long> t;
	while(x >= 10){
		t.insert(x%10);
		x/=10; c++;
	}
	t.insert(x);
	return t.size();
}
void dfs(long long x){
	if(x <= n and x > 0) ans++;
	if(x >= n or x >= 1e9) return;
	for (int i = 0; i < 10; ++i){
		if(x*10+i > 0 and x*10+i <= n)
			if(dig(x*10+i) <= 2) dfs(x*10+i);
	}
		
}
int main(){


	cin >> n;
	ans = 0;
	dfs(0);
	cout << ans;
	return 0;
}