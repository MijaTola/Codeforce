#include <iostream>

using namespace std;
typedef long long ll;
int main(){
	int n;
	cin >> n;
	ll x;
	ll ans = 0;
	for (int i = 1; i <= n; ++i){
		cin >> x;
		ans += (x-1)*i+1;
	}
	cout << ans << endl;
	return 0;
}
