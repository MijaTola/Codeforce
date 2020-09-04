#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,l,c,d,p,nl,np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int m = (k*l)/nl;
	int x = d*c;
	int y = p/np;
	/*cout << m << endl;
	cout << x << endl;
	cout << y << endl;*/
	cout << min(m,min(x,y))/n << endl;
	return 0;
}