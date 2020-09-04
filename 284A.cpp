#include <bits/stdc++.h>

using namespace std;

int main(){
	int p,j;
	cin >> p;
	int ans = 0;
	for (int i = 1; i < p; ++i)
	{
		int t = 1;
		for(j = 1; j < p-1; ++j){
			t = (t*i)%p;
			if(t == 1) break;
		}
		if(j == p-1 and (t*i)%p == 1) ans++;
	}

	cout << ans;
	return 0;
}