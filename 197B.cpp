#include <bits/stdc++.h>

using namespace std;

int dm[105]; int dn[105];
int main(){
	int n,m;
	cin >> n >> m;
	int inf = 999999;
	int num = 0;
	bool ind = false;
	
	for (int i = 0; i <= n; ++i)
			cin >> dn[i];

		for (int i = 0; i <= m; ++i)
			cin >> dm[i];

	if(n < m) return cout << "0/1",0;
	if(n > m){
		if(dn[0]*dm[0] > 0) cout << "Infinity";
		else cout << "-Infinity";
		return 0;
	}
	if(n == m){
		int g = __gcd(abs(dn[0]),abs(dm[0]));
		if(dn[0]*dm[0] < 0) cout << "-"<<abs(dn[0])/g << "/" << abs(dm[0])/g;
		else cout << abs(dn[0])/g << "/" << abs(dm[0])/g;
		return 0;
	}
	return 0;
	
}