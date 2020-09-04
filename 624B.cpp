#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
	int n;
	map<ll,bool> m;
	cin >> n;
	ll x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if(!m[x]) m[x] = true;
		else{
			while(true){
				x--;
				if(!m[x]){
					m[x] = true; 
					break;
				}
				if(x == 0) break;
			}
		}
	}

	ll ans = 0;
	for (std::map<ll,bool>::iterator i = m.begin(); i != m.end(); ++i)
	{
		if(i->second) ans += i->first;
	}
	cout << ans;
	return 0;
}