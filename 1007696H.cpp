#include <iostream>

using namespace std;

typedef unsigned long long ll;
int main(){
	ll n,m; cin >> n >> m;
	if(n == m) cout << n*(m+1) << endl;
	else if(n > m){
		ll a = m*(m+1);
		n -= m;
		a += n*m;
		cout << a << endl;
	}else{
		ll a = n*(n+1);
		m -= n;
		a += n*m;
		cout << a << endl;
	}
	return 0;
}
