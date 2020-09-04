#include <bits/stdc++.h>

using namespace std;

int main(){
	int dn[3005];
	int dm[3005];
	int n, m;
	bool ver[1000006];
	memset(ver,false,sizeof ver);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> dn[i];

	int pos = 0;
	for (int i = 0; i < m; ++i){
		cin >> dm[i];
		if(dm[i] >= dn[pos] and !ver[dn[pos]])
		{	
			ver[dn[pos]] = true;
			if(pos < n) pos++;
		}
	}
	cout << n - pos;
	return 0;
}