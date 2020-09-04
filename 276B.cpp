#include <bits/stdc++.h>

using namespace std;

int main(){
	map<char,int> m;
	string x;
	cin >> x;
	for (int i = 0; i < x.size(); ++i) m[x[i]]++;

	int ans = 0;
	
	for (int i = 0; i < x.size(); ++i)
		if(m[x[i]] % 2 != 0) ans++;
	if(ans%2 != 0 or ans == 0) cout << "First";
	else cout << "Second";
	
	return 0;
}