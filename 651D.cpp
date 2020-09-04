#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,a,b,t;
	cin >> n >> a >> b >> t;
	if(a > t) return cout << 0,0;
	int v[500000];
	memset(v,0,sizeof v);
	int ans = 0;
	bool sw = false;
	for (int i = 0; i < n; ++i)
	{
		char x;
		cin >> x;
		if(x == 'w'){
			v[i] = b;
			if(b > t) return cout << 0,0;
		} 
		v[i]++;
		v[i] += a;
	}
	int t1 = -1;
	for (int i = 0; i < n; ++i)
	{
		ans += v[i];
		if(ans > t){
			t1 = abs(i - 0);
			sw = true;
			break;
		}
	}
	if(!sw) return cout << n,0;
	ans = v[0];
	int t2 = -1;
	sw = false;
	for (int i = n-1; i >= 1; --i)
	{
		ans += v[i];
		if(ans > t){
			t2 = abs(n - i);
			sw = true;
			break;
		}
	}
	if(!sw) t2 = n;
	/*if(t1 > t2) cout << t1+1;
	else cout << t2+1;*/
	cout << t1 << " " << t2;

	return 0; 
}