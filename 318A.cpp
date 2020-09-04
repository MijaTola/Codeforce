#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll n,k;
	vector<ll> t;
	cin >> n >> k;
	if(k <= (n+1)/2) cout << 2*k-1;
	else cout << (k-(n+1)/2)*2;
	return 0;
}