#include <iostream>

using namespace std;

typedef long long ll;
int main(){
	ll n;
	ll ans = 1;
	cin >> n;
	ll x = n;
	for (ll i = 2; i*i <= n; ++i){
		if(x%i == 0){
			ans*= (ll)i;
			while(x%i == 0)
				x/= i;	
		}
	}
	if(x>1)	
		ans *= x;
	cout << ans << endl;
	
	return 0;
}