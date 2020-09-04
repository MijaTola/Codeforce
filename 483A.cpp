#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){

	ll l,r;
	cin >> l >> r;

	ll s = l+l%2;
  	if (s+2 > r) {
    cout << -1;
    return 0;
  	}
 	cout << s << " " << s+1 << " " << s+2;
	return 0;
}