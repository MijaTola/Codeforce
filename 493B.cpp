#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ver(vector<ll> x, vector<ll> y){
	bool sw = false;
		for (int i = 0; i < x.size(); ++i)
		{
			if(i == y.size()) return true;
			if(x[i] > y[i]) return true;
			if(x[i] < y[i]) return false;
		}
		return false;
}
int main(){
	ll n;
	vector<ll> x;
	vector<ll> y;
	cin >> n;
	ll dx = 0;
	ll dy = 0;
	ll t = 0;
	for (ll i = 0; i < n; ++i)
	{
		cin >> t;
		if(t < 0){ y.push_back(-1*t); dy += t*-1;}
		else{ x.push_back(t); dx += t;}
	}
	if(dy > dx) cout << "second";
	else if(dx > dy) cout << "first";
	else if(ver(x,y)) cout << "first";
	else if(ver(y,x)) cout << "second";
	else if(t > 0) cout << "first";
	else if(t < 0) cout << "second";
	return 0;
}