#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll solve(ll l){
	return l*(l-1)/2;
}
int main(){
	ll x,y;
	cin >> x >> y;

	ll maxi = solve(x-y+1);

	ll mini = (y-(x%y))*solve(x/y) + (x%y)*solve(x/y+1);

	cout << mini << " " << maxi; 
	return 0;
}	