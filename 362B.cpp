#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ll n, m,x;
	cin >> n >> m;
	ll pos = 0;
	vector<ll> s;
	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		if(x == 1 or x == n){
			cout << "NO"; return 0;
		}
		s.push_back(x);
	}
	sort(s.begin(), s.end());
	bool sw = false;
	int c = 0; 
	for (int i = 0; i < m; ++i)
	{
		if(s[i] + 1 == s[i+1]){
			c++;
			sw = true;
			if(c > 1){
				cout << "NO"; return 0;
			}
		}else{
			sw = false; c = 0;
		}
	}

	cout << "YES";
	return 0;
}