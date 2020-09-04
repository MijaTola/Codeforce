#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll d,p;
	cin >> p >> d;
	ll rest = p - d;
	ll k = 1;
	ll ans = p;
	while(p >= rest){
		while(p%(10*k)-1 != -1) p -= k;
		if(p >= rest) ans = p;
		k*=10;
	}
	cout << ans -1<< endl;
	return 0;
}