#include <bits/stdc++.h>

using namespace std;

#define pb push_back
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans;
	int d = 2;
	ans.pb(n);
	while(n != 1){
		if(n%d== 0){
			n/=d;
			ans.pb(n);
			d=2;
		}else d++;
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}