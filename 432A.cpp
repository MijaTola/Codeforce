#include <bits/stdc++.h>

using namespace std;


int main(){

	int n,k,y;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		cin >> y;v.push_back(y);
	}
	sort(v.begin(),v.end());
	int ans = 0;
	for (int i = 0; i < v.size(); ++i)
		if(5-v[i] >= k) ans++;
	if(ans >= 3) cout << ans/3 << endl;
	else cout << 0 << endl;

	return 0;
}