#include <bits/stdc++.h>

using namespace std;

int main(){

	bool v[3010];

	int n,x;

	cin >> n;
	memset(v,false,sizeof v);
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v[x] = true;
	}

	for (int i = 1; i <= 3010; ++i)
		if(!v[i]){
			cout << i; break;}
	return 0;
}