#include <bits/stdc++.h>

using namespace std;

int main(){
	int v[50000];
	int n,k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		if(k > 0) cout << 2*i+2 << " " << 2*i + 1 << " ";
		else cout << 2*i+1 << " " << 2*i + 2 << " ";
		k--;
	}

	return 0;
}

/*
4 0
2 7 4 6 1 3 5 8
*/	