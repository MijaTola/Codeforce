#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){

	string x;
	cin >> x;
	ll mid;
	for (ll i = 0; i < x.size(); ++i)
		if(x[i] == '^'){mid = i; break;}

	ll left= 0;
	ll right = 0;
	for (ll i = 0; i < x.size(); ++i)
	{
		if(x[i] == '=' ||x[i] == '^') continue;
		if(i < mid) (left += (x[i]-48)*abs(mid-i));
		else right += ((x[i]-48)*abs(mid-i));
	}
	if( right< left )cout<<"left\n";
    else if( right> left )cout<<"right\n";
    else cout<<"balance\n";
}