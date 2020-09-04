#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	map<string,bool> m;
	cin >> n;
	string x;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if(isdigit(x[0])){
			istringstream ss(x);
			int t; ss >> t;
			if(t < 18) ans++;
		}else if(x =="ABSINTH" or x =="BEER" 
			or x =="BRANDY" or x == "CHAMPAGNE" 
			or x == "SAKE" or x == "GIN" or x == "RUM" 
			or x == "TEQUILA" or x == "VODKA" 
			or x == "WHISKEY" or x == "WINE")
						ans++;
	}
	cout << ans;
	return 0;
}