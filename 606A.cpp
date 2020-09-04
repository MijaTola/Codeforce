#include <bits/stdc++.h>

using namespace std;

int main(){

	int a,b,c,x,y,z;

	cin >> a >> b >> c >> x >> y >> z;

	int p = max(a - x,0)/2+max(b-y,0)/2 + max(c-z,0)/2;
	int n = max(x -a,0)+ max(y - b,0) + max(z - c, 0);

	if(p >= n) cout << "YES";
	else cout << "NO";

		
	return 0;
}