#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> v;
	int n,m,x;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int pos = 0;
	int c = 0;
	int ans = 0;
	while(v[pos] < 0 and pos < m and pos < n){
		ans += v[pos]; pos++;
	}
	cout << abs(ans);
	return 0;
}