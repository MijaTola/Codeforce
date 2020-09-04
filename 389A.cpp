#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x,y;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i){
		cin >> x;
		ans = __gcd(ans,x);
	}
	cout <<  ans*n;
	return 0;
}