#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,m,x;
	vector<int> f;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		f.push_back(x);
	}
	sort(f.begin(),f.end());
	int ans = 9999999;

	for (int i = 0; i <= m-n; ++i)
	{
		ans = min(ans,f[i+n-1] - f[i]);
	}
	cout << ans << endl;
	return 0;
}