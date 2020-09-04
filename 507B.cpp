#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){

	ll r,x,y,a,b;
	cin >> r >> x >> y >> a >> b;

	ll dx = (x-a)*(x-a);
	ll dy = (y-b)*(y-b);
	double d = sqrt(dx+dy);
	double ans = d/(2*r);
	if(ans != (ll)ans) ans++;
	//cout << d << endl;
	cout << (ll)ans;

	return 0;
}