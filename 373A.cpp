#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	char p;
	cin >> k;
	int v[10];
	memset(v,0,sizeof v);
	bool sw = true;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			cin >> p;
			if(p == '.') continue;
			int x = p - 48;
			v[x]++;
			if(v[x] > k*2) sw = false;
		}

	if(sw) cout << "YES";
	else cout << "NO";
	return 0;
}