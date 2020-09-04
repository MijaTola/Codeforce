#include <bits/stdc++.h>

using namespace std;
int da[50],db[50];
int dd[50],dc[50];
int main(){
	int p,q,l,r;
	cin >> p >> q >> l >> r;
	int c,d;
	for (int i = 0; i < p; ++i)
		cin >> da[i] >> db[i];
	int ans = 0;
	for(int i = 0; i < q; ++i)
		cin >> dc[i] >> dd[i];

	for(int t = l; t <= r; ++t){
		int r = 0;	
		for(int i = 0; i < p; ++i)
			for(int j = 0; j < q; ++j)
				if(da[i] <= dc[j] + t and db[i] >= dc[j] + t or dd[j] + t >= da[i] and dc[j] + t <= da[i]) r = 1;
		ans += r;
	}
	cout << ans;
	return 0;
}
