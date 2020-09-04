#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,k;
	string x;
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;		
		int c = 0;
		if(x.size() < k){
			ans++;
			continue;
		}
		for (int j = 0; j < x.size(); ++j)
			if(x[j] == '4' || x[j] == '7') c++;
		if(c <= k) ans++;
	}
	cout << ans << endl;
	return 0;
}