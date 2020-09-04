#include <bits/stdc++.h>

using namespace std;

int main(){
	int d,n,a;

	cin >> d >> n;

	int ans = 0;
	while(n--){
		cin >> a;
		if(n)ans += d - a;
	}

	cout << ans;

	return 0;
}