#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	int v[1050];
	int maxi = -1;
	cin >> n;
	memset(v,0,sizeof v);
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v[x]++;
		if(v[x] > maxi) maxi = v[x];
	}
	if(maxi > (n+1)/2) cout << "NO";
	else cout << "YES";
	return 0;
}