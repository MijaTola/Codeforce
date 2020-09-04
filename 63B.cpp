#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int v[123];
	bool d[123];
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int ans = 0;
	while(true){
		memset(d,false,sizeof d);
		bool sw = false;
		for (int i = 0; i < n; ++i)
		{
			if(!d[v[i]] and v[i] < k){
				d[v[i]] = true;
				v[i]++;
				sw = true;
			}
		}
		if(!sw) break;
		ans++;
	}
	cout << ans;
	return 0;
}