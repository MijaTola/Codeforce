#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	//ios::sync_with_stdio(false); cin.tie(0);
	int v[10000];
	int n,m,d;
	cin >> n >> m >> d;

	int di = n*m;

	for (int i = 0; i < di; ++i)
		cin >> v[i];
	//sort(v,v+di);

	int ans = 1999999999;
	for (int i = 0; i < di; ++i)
	{
	int c = 0;
		bool ver = true;
		for (int j = 0; j < di; ++j)
		{
			int dis = abs(v[i] - v[j]);
			if(dis%d == 0){
				c += dis/d;
			}else{
				ver = false;
				break;
			}
		}
		if(ver) ans = min(ans, c);
	}
	if(ans == 1999999999) cout << -1;
	else cout << ans;
	return 0;
}