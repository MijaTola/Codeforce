#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,d,l;
	int ans[101];
	int s = 0;
	cin >> n >> d >> l;

	for (int i = 0; i < n; ++i)
	{
		ans[i] = (i&1) ? -1 : 1;
		s += ans[i];	
	}
	bool sw = false;
	while(true){
		if(s == d)break;
		sw = false;
		if(s < d){
			for (int i = 0; i < n; ++i)
			{
				if(ans[i] < l and ans[i] > 0){
					ans[i]++; s++; 
					sw = true;break;
				}
			}

		}else if(s > d){
			for (int i = 0; i < n; ++i)
			{
				if(ans[i] < 0 and ans[i] > -l){
					ans[i]--; s--;sw = true; break;
				}
			}

		}
		if(!sw) return cout <<-1,0;
	}
	for (int i = 0; i < n; ++i)
		cout << abs(ans[i]) << " ";
	
	return 0;
}