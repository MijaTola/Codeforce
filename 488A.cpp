#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin >> n;
	int ans = 1;
	for (int i = n+1; i < 8888888888; ++i)
	{
		stringstream ss;
		ss << i;
		string t = ss.str();
		bool sw = false;
		for (int f = 0; f < t.size(); ++f)
		{
			if(t[f] == '8') sw = true;
		}
		if(sw) break;
		ans++;
	}

	cout << ans;

	return 0;
}