#include <bits/stdc++.h>

using namespace std;

int main(){
	int d,st,da[30],db[30],ans[30];
	int smin,smax;
	cin >> d >> st;

	for (int i = 0; i < d; ++i)
	{
		cin >> da[i] >> db[i];
		smin += da[i];
		smax += db[i];
	}
	if(smin > st or smax < st) {
		cout << "NO"; return 0;
	}
	bool sw = false;
	cout << "YES" << endl;
	for (int i = 0; i < d; ++i)
	{
		if(!sw){
			if(st - smin <= db[i] - da[i]){
				sw = true;
				ans[i] = da[i] + st - smin;
			}else{
				ans[i] = db[i];
				smin += db[i] - da[i];
			}
		}else ans[i] = da[i];
	}
	for (int i = 0; i < d; ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}