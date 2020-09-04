#include <bits/stdc++.h>

using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(0);
	int m,n,x;
	cin >> n >> m;
	int ones = 0,zeros = 0;
	for (int i = 0; i < n; ++i){
		cin >> x;
		if(x == 1) ones++;
		else zeros++;
	}
	int l,r;
	for (int i = 0; i < m; ++i)
	{
		cin >> l >> r;
		int dif = r - l + 1;
		if(dif % 2) cout << 0 << endl;
		else{ 
			if(ones >= dif/2 && zeros >= dif/2) cout << 1 << endl;
				else cout << 0 << endl;
		}
	}
	return 0;
}