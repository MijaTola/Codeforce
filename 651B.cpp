#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[1000];
	bool b[1010];
	memset(b,false,sizeof b);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		//b[i] = a[i];
	}
	sort(a,a+n);
	int ans = 0;
	/*for (int i = 0; i < n; ++i)
		cout << a[i] << " ";*/

	//cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j){
			if(b[j]) continue;
			if(a[i] < a[j]){
		//		cout << a[i] <<" "<< a[j] << endl;
				ans++;
				b[i] = true;
				b[j] = true;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}