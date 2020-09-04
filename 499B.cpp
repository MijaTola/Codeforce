#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,t;
	string x,y;
	map<string,int> m;
	string v[3001];
	cin >> n >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> x >> y;
		if(x.size() <= y.size()) v[i] = x;
		else v[i] = y;
		m[x] = i;
	}
	string ans = "";
	while(n--){
		cin >> x;
		ans += v[m[x]];
		if(n) ans += " ";
	}
	cout << ans;
	return 0;
}