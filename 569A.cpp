#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,q,s;
	cin >> t >> s >> q;
	int ans = 0;
	while(s < t){
		s *= q;
		ans++;
	}
	cout << ans;
	return 0;
}