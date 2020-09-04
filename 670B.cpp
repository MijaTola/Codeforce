#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
ll v[1100010];
vector <ll> xd;
ll n,k;
int main(){

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> v[i];
	ll a = -1 , b =  987645616LL;
	while( b - a > 1 ){
		ll mid = ( a + b ) >> 1;
		if((mid*(mid+1))/2 >= k )b = mid;
		else a = mid;
	}
	
	int pos = a;
	long long ret = a*(a+1LL)/2LL;
	cout << v[ k - ret ] << endl;
	return 0;
}
