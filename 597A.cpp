#include <iostream>

using namespace std;

typedef long long ll;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll k,a,b,p,dif;
	cin >> k >> a >> b;
	 p = a/k;
	if(a%k > 0) p++;
	a = p*k;	
	dif = (b - a)/k+1;
	if(a > b) dif = 0;
	cout << dif << endl;
	return 0;
}